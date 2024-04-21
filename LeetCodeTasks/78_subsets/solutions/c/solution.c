#include <stdlib.h>
#include <math.h>

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int totalSubsets = 1 << numsSize; // Calculate 2^numsSize
    *returnSize = totalSubsets;
    int **result = malloc(totalSubsets * sizeof(int*));
    *returnColumnSizes = malloc(totalSubsets * sizeof(int));

    for (int i = 0; i < totalSubsets; i++) {
        int *subset = malloc(numsSize * sizeof(int));
        int subsetSize = 0;
        for (int j = 0; j < numsSize; j++) {
            if (i & (1 << j)) { // Check if the jth bit is set in i
                subset[subsetSize++] = nums[j];
            }
        }
        result[i] = malloc(subsetSize * sizeof(int));
        for (int k = 0; k < subsetSize; k++) {
            result[i][k] = subset[k];
        }
        free(subset);
        (*returnColumnSizes)[i] = subsetSize;
    }

    return result;
}
