#include <stdio.h>
#include <stdlib.h>

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = *gridColSize;
    for (int i = 1; i < m; ++i) {
        grid[i][0] += grid[i-1][0];
    }
    for (int j = 1; j < n; ++j) {
        grid[0][j] += grid[0][j-1];
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            grid[i][j] += (grid[i-1][j] < grid[i][j-1] ? grid[i-1][j] : grid[i][j-1]);
        }
    }
    return grid[m-1][n-1];
}
