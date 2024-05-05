#include <stdlib.h>

int minimumOperations(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int operations = 0;

    // Check vertical alignment, i.e., each cell should be the same as the one below it.
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m - 1; i++) {
            if (grid[i][j] != grid[i + 1][j]) {
                operations++;
                grid[i + 1][j] = grid[i][j];  // mimic the operation needed to make them the same
            }
        }
    }

    // Check horizontal uniqueness, i.e., each cell should be different from the one to its right.
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (grid[i][j] == grid[i][j + 1]) {
                operations++;
                // Ensure next cell is different by changing it to any number different from the current one
                // As we are dealing with numbers 0-9, we can simply cycle to the next number modulo 10
                grid[i][j + 1] = (grid[i][j] + 1) % 10;  
            }
        }
    }

    return operations;
}
