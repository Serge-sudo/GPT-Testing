#include <stdbool.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    bool isFirstRowZero = false, isFirstColZero = false;
    int i, j;

    // Check if the first row contains zero
    for (j = 0; j < *matrixColSize; j++) {
        if (matrix[0][j] == 0) {
            isFirstRowZero = true;
            break;
        }
    }

    // Check if the first column contains zero
    for (i = 0; i < matrixSize; i++) {
        if (matrix[i][0] == 0) {
            isFirstColZero = true;
            break;
        }
    }

    // Use first row and column as markers
    for (i = 1; i < matrixSize; i++) {
        for (j = 1; j < *matrixColSize; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set zeroes based on markers
    for (i = 1; i < matrixSize; i++) {
        for (j = 1; j < *matrixColSize; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Set zeroes in the first row if needed
    if (isFirstRowZero) {
        for (j = 0; j < *matrixColSize; j++) {
            matrix[0][j] = 0;
        }
    }

    // Set zeroes in the first column if needed
    if (isFirstColZero) {
        for (i = 0; i < matrixSize; i++) {
            matrix[i][0] = 0;
        }
    }
}
