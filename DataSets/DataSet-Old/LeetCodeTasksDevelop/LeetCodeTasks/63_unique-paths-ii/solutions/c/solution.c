#include <stdio.h>
#include <stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m = obstacleGridSize;
    int n = *obstacleGridColSize;
    if (obstacleGrid[0][0] == 1) return 0;

    int* dp = (int*)calloc(n, sizeof(int));
    dp[0] = 1;  // Starting point

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[j] = 0;  // No path through an obstacle
            } else if (j > 0) {
                dp[j] += dp[j - 1];  // Add the paths from the left
            }
        }
    }

    int result = dp[n - 1];
    free(dp);
    return result;
}
