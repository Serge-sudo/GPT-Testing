#include <stdlib.h>

int** resultGrid(int** image, int imageSize, int* imageColSize, int threshold, int* returnSize, int** returnColumnSizes) {
    int m = imageSize;
    int n = imageColSize[0];
    *returnSize = m;
    *returnColumnSizes = malloc(m * sizeof(int));
    int** result = malloc(m * sizeof(int*));

    for (int i = 0; i < m; i++) {
        result[i] = malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    // Check each possible 3x3 subgrid
    for (int i = 0; i < m - 2; i++) {
        for (int j = 0; j < n - 2; j++) {
            int valid = 1;
            int sum = 0;
            // Verify the subgrid is a valid region
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    sum += image[i + x][j + y];
                    if (x < 2 && abs(image[i + x][j + y] - image[i + x + 1][j + y]) > threshold) {
                        valid = 0;
                    }
                    if (y < 2 && abs(image[i + x][j + y] - image[i + x][j + y + 1]) > threshold) {
                        valid = 0;
                    }
                }
            }
            if (valid) {
                int avg = sum / 9; // Rounded down average of the region
                // Add average to all cells in the region
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        if (result[i + x][j + y] == 0) {
                            result[i + x][j + y] = avg;
                        } else {
                            // If already part of another region, average both rounded down values
                            result[i + x][j + y] = (result[i + x][j + y] + avg) / 2;
                        }
                    }
                }
            }
        }
    }

    // Fill in the pixels that are not part of any region
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (result[i][j] == 0) { // No region includes this pixel
                result[i][j] = image[i][j];
            }
        }
    }

    return result;
}
