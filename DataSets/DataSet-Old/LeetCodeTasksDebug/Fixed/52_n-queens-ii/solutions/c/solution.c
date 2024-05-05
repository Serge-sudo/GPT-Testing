#include <stdbool.h>

int totalNQueens(int n) {
    int solutions = 0;
    int queens[n]; // Position of queens, index is the row, value is the column

    int row = 0, col = 0;

    while (row >= 0) {
        while (col < n) {
            bool valid = true;

            for (int i = 0; i < row; ++i) {
                int prevCol = queens[i];
                if (prevCol == col || prevCol == col - (row - i) || prevCol == col + (row - i)) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                queens[row] = col;
                row++;
                col = 0;
                break;
            } else {
                col++;
            }
        }

        if (col == n) { // No valid column found in this row
            if (row == n) { // All queens are placed
                solutions++;
            }
            row--;
            if (row >= 0) {
                col = queens[row] + 1;
            }
        }
    }

    return solutions;
}
