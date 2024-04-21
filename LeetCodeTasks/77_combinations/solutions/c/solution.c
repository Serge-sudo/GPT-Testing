#include <stdlib.h>

void backtrack(int n, int k, int start, int* temp, int tempSize, int** result, int* returnSize, int** returnColumnSizes) {
    if (tempSize == k) {
        result[*returnSize] = (int*) malloc(k * sizeof(int));
        for (int i = 0; i < k; i++) {
            result[*returnSize][i] = temp[i];
        }
        (*returnColumnSizes)[*returnSize] = k;
        (*returnSize)++;
        return;
    }

    for (int i = start; i <= n; i++) {
        temp[tempSize] = i;
        backtrack(n, k, i + 1, temp, tempSize + 1, result, returnSize, returnColumnSizes);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    int** result = (int**) malloc(100000 * sizeof(int*));
    *returnColumnSizes = (int*) malloc(100000 * sizeof(int));
    *returnSize = 0;
    int* temp = (int*) malloc(k * sizeof(int));

    backtrack(n, k, 1, temp, 0, result, returnSize, returnColumnSizes);

    free(temp);
    return result;
}
