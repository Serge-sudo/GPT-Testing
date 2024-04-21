#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int rows = matrixSize;
    int cols = matrixColSize[0];
    *returnSize = rows * cols;
    int* result = (int*)malloc(*returnSize * sizeof(int));
    
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    int index = 0;
    
    while (top <= bottom && left <= right) {
        // Traverse from left to right along the top row
        for (int j = left; j <= right; j++) {
            result[index++] = matrix[top][j];
        }
        top++;
        
        // Traverse from top to bottom along the right column
        for (int i = top; i <= bottom; i++) {
            result[index++] = matrix[i][right];
        }
        right--;
        
        if (top <= bottom) {
            // Traverse from right to left along the bottom row
            for (int j = right; j >= left; j--) {
                result[index++] = matrix[bottom][j];
            }
            bottom--;
        }
        
        if (left <= right) {
            // Traverse from bottom to top along the left column
            for (int i = bottom; i >= top; i--) {
                result[index++] = matrix[i][left];
            }
            left++;
        }
    }
    
    return result;
}
