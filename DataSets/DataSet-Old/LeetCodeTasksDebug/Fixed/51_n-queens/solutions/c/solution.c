#include <stdlib.h>

#include <string.h>



void placeQueens(int n, int row, char** board, int* cols, int* diag1, int* diag2, char**** solutions, int* returnSize, int** returnColumnSizes) {

    if (row == n) {

        // Save solution

        char** solution = (char**)malloc(sizeof(char*) * n);

        for (int i = 0; i < n; ++i) {

            solution[i] = (char*)malloc(sizeof(char) * (n + 1));

            strcpy(solution[i], board[i]);

        }

        (*returnSize)++;

        *solutions = (char***)realloc(*solutions, sizeof(char**) * (*returnSize));

        (*solutions)[*returnSize] = solution;

        *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * (*returnSize));

        (*returnColumnSizes)[*returnSize - 1] = n;

        return;

    }

    

    for (int col = 0; col < n; ++col) {

        if (!cols[col] && !diag1[row + col] && !diag2[row - col + n - 1]) {

            board[row][col] = 'Q';

            cols[col] = diag1[row + col] = diag2[row - col + n] = 1;

            

            placeQueens(n, row + 1, board, cols, diag1, diag2, solutions, returnSize, returnColumnSizes);

            

            board[row][col] = '.';

            cols[col] = diag1[row + col] = diag2[row - col + n] = 0;

        }

    }

}



char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {

    *returnSize = 0;

    *returnColumnSizes = NULL;

    char*** solutions = NULL;

    

    char** board = (char**)malloc(sizeof(char*) * n);

    for (int i = 0; i < n; ++i) {

        board[i] = (char*)malloc(sizeof(char) * (n + 1));

        for (int j = 0; j < n; ++j) {

            board[i][j] = '.';

        }

        board[i][n] = '\0';

    }

    

    int* cols = (int*)calloc(n, sizeof(int));

    int* diag1 = (int*)calloc(2 * n - 1, sizeof(int));

    int* diag2 = (int*)calloc(2 * n - 1, sizeof(int));

    

    placeQueens(n, 0, board, cols, diag1, diag2, &solutions, returnSize, returnColumnSizes);

    

    for (int i = 0; i < n; ++i) {

        free(board[i]);

    }

    free(board);

    free(cols);

    free(diag1);

    free(diag2);

    

    return solutions;

}

