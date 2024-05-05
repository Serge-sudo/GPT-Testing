#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0) return 0;
    int cols = matrixColSize[0];
    int *height = (int *)calloc(cols, sizeof(int));
    int *left = (int *)calloc(cols, sizeof(int));
    int *right = (int *)calloc(cols, sizeof(int));
    int maxArea = 0;

    for (int i = 0; i < cols; i++) {
        right[i] = cols;
    }

    for (int i = 0; i < matrixSize; i++) {
        int cur_left = 0, cur_right = cols;
        // update height
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                height[j]++;
            } else {
                height[j] = 0;
            }
        }
        // update left
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                left[j] = left[j] > cur_left ? left[j] : cur_left;
            } else {
                left[j] = 0; cur_left = j + 1;
            }
        }
        // update right
        for (int j = cols - 1; j >= 0; j--) {
            if (matrix[i][j] == '1') {
                right[j] = right[j] < cur_right ? right[j] : cur_right;
            } else {
                right[j] = cols; cur_right = j;
            }
        }
        // compute the area of rectangle
        for (int j = 0; j < cols; j++) {
            maxArea = maxArea > (right[j] - left[j]) * height[j] ? maxArea : (right[j] - left[j]) * height[j];
        }
    }

    free(height);
    free(left);
    free(right);
    return maxArea;
}
