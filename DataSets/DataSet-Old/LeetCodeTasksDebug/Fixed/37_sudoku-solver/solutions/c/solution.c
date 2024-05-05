#include <stdbool.h>

bool is_valid(char **board, int row, int col, char num) {
    int block_row = (row / 3) * 3;
    int block_col = (col / 3) * 3;
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) return false;
        if (board[i][col] == num) return false;
        if (board[block_row + i / 3][block_col + i % 3] == num) return false;
    }
    return true;
}

bool solve(char **board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {
                for (char num = '1'; num <= '9'; num++) {
                    if (is_valid(board, row, col, num)) {
                        board[row][col] = num;
                        if (solve(board)) {
                            return true;
                        }
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(char **board, int boardSize, int *boardColSize) {
    solve(board);
}
