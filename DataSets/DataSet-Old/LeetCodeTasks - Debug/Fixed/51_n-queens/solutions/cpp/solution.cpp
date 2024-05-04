#include <vector>

#include <string>



class Solution {

public:

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> results;

        vector<string> board(n, string(n, '.'));

        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);

        

        function<void(int)> solve = [&](int col) {

            if (col == n) {

                results.push_back(board);

                return;

            }

            for (int row = 0; row < n; ++row) {

                if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n + col - row] == 0) {

                    board[row][col] = 'Q';

                    leftRow[row] = 1;

                    lowerDiagonal[row + col] = 1;

                    upperDiagonal[n - 1 + col - row] = 1;

                    

                    solve(col);

                    

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

