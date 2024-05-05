#include <vector>
#include <string>
#include <functional>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> results;
        std::vector<std::string> board(n, std::string(n, '.'));
        std::vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        
        std::function<void(int)> solve = [&](int col) {
            if (col == n) {
                results.push_back(board);
                return;
            }
            for (int row = 0; row < n; ++row) {
                if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
                    board[row][col] = 'Q';
                    leftRow[row] = 1;
                    lowerDiagonal[row + col] = 1;
                    upperDiagonal[n - 1 + col - row] = 1;
                    
                    solve(col + 1);
                    
                    board[row][col] = '.';
                    leftRow[row] = 0;
                    lowerDiagonal[row + col] = 0;
                    upperDiagonal[n - 1 + col - row] = 0;
                }
            }
        };
        
        solve(0);
        return results;
    }
};
