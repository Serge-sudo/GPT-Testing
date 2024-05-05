#include <stdlib.h>

int countSubmatrices(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = gridColSize[0];
    int count = 0;
    
    // Prefix sum matrix to allow quick calculation of submatrix sums
    int** sum = (int**) malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; ++i) {
        sum[i] = (int*) calloc(n + 1, sizeof(int));
    }
    
    // Building the prefix sum matrix
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            sum[i][j] = grid[i-1][j-1]
                        + sum[i-1][j]
                        + sum[i][j-1]
                        - sum[i-1][j-1];
        }
    }
    
    // Check all submatrices that include the top-left element (0,0)
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int submatrixSum = sum[i][j]; // Since the submatrix starts from (0, 0)
            if (submatrixSum <= k) {
                count++;
            }
        }
    }
    
    // Freeing the allocated memory for sum matrix
    for (int i = 0; i <= m; ++i) {
        free(sum[i]);
    }
    free(sum);
    
    return count;
}
