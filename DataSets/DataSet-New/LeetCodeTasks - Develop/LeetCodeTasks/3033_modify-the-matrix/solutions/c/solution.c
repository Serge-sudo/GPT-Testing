#include <stdlib.h>

int** modifiedMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int m = matrixSize;
    int n = *matrixColSize;
    
    // Allocate the answer matrix.
    int** answer = (int**) malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        answer[i] = (int*) malloc(n * sizeof(int));
    }
    
    // Copy the original matrix to the answer matrix.
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            answer[i][j] = matrix[i][j];
        }
    }
    
    // Find the maximum value in each column.
    int* maxInColumn = (int*) malloc(n * sizeof(int));
    for (int j = 0; j < n; j++) {
        int maxVal = -1;
        for (int i = 0; i < m; i++) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
        maxInColumn[j] = maxVal;
    }
    
    // Replace `-1` with the maximum value in its column.
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
                answer[i][j] = maxInColumn[j];
            }
        }
    }
    
    // Set the output parameters.
    *returnSize = m;
    *returnColumnSizes = (int*) malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
    }
    
    free(maxInColumn); // Free the temporary array used.
    
    return answer;
}
