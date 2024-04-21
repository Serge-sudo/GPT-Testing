#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void swap(int *nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void backtrack(int *nums, int numsSize, int start, int **res, int *returnSize, int *temp) {
    if (start == numsSize) {
        res[*returnSize] = (int *)malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            res[*returnSize][i] = temp[i];
        }
        (*returnSize)++;
    } else {
        for (int i = start; i < numsSize; i++) {
            if (i != start && nums[i] == nums[start]) continue;
            swap(nums, start, i);
            temp[start] = nums[start];
            backtrack(nums, numsSize, start + 1, res, returnSize, temp);
            swap(nums, start, i);
        }
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int **res = (int **)malloc(40320 * sizeof(int *)); // 8! permutations
    *returnColumnSizes = (int *)malloc(40320 * sizeof(int));
    *returnSize = 0;
    int *temp = (int *)malloc(numsSize * sizeof(int));
    backtrack(nums, numsSize, 0, res, returnSize, temp);
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    free(temp);
    return res;
}
