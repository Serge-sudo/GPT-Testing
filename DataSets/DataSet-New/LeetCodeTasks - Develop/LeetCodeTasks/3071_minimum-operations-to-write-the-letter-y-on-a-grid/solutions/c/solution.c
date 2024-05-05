#include <stdlib.h>
#include <limits.h>

int minimumOperationsToWriteY(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int center = n / 2;
    int minChanges = INT_MAX;
    
    // Attempt each combination of values for Y and non-Y parts
    for (int yValue = 0; yValue < 3; yValue++) {
        for (int nonYValue = 0; nonYValue < 3; nonYValue++) {
            if (yValue == nonYValue) continue;
            int changes = 0;
            
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++) {
                    // Check if cell belongs to the Y
                    if (r == c && r <= center) {  // Top-left to center diagonal
                        if (grid[r][c] != yValue) changes++;
                    } else if (r + c == n - 1 && r <= center) {  // Top-right to center diagonal
                        if (grid[r][c] != yValue) changes++;
                    } else if (r >= center && c == center) {  // Center down vertical line
                        if (grid[r][c] != yValue) changes++;
                    } else {  // Cells not part of Y
                        if (grid[r][c] != nonYValue) changes++;
                    }
                }
            }
            
            if (changes < minChanges) {
                minChanges = changes;
            }
        }
    }
    
    return minChanges;
}
