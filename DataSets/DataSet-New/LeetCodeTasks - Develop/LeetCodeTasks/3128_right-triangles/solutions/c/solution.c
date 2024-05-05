#include <stdbool.h>

long long numberOfRightTriangles(int** grid, int gridSize, int* gridColSize) {
    long long count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                long long row_count = 0;
                long long col_count = 0;
                for (int k = 0; k < gridSize; k++) {
                    if (grid[k][j] == 1 && k != i) {
                        col_count++;
                    }
                }
                for (int k = 0; k < gridColSize[i]; k++) {
                    if (grid[i][k] == 1 && k != j) {
                        row_count++;
                    }
                }
                count += row_count * col_count;
            }
        }
    }
    return count;
}
