#include <vector>

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        solve(board);
    }
    
private:
    bool solve(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (char num = '1'; num <= '9'; ++num) {
                        if (isValid(board, i, j, num)) {
                            board[i][j] = num;
                            if (solve(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(const std::vector<std::vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == num) return false; // Check row
            if (board[row][i] == num) return false; // Check column
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) return false; // Check 3x3 box
        }
        return true;
    }
};
