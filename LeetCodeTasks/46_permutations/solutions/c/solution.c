#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void generatePermutations(int* nums, int numsSize, int start, int** res, int* count) {
    if (start == numsSize) {
        res[*count] = (int*)malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            res[*count][i] = nums[i];
        }
        (*count)++;
    } else {
        for (int i = start; i < numsSize; i++) {
            swap(&nums[start], &nums[i]);
            generatePermutations(nums, numsSize, start + 1, res, count);
            swap(&nums[start], &nums[i]);
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int maxPermutations = 1;
    for (int i = 1; i <= numsSize; i++) {
        maxPermutations *= i;
    }
    int** res = (int**)malloc(maxPermutations * sizeof(int*));
    *returnSize = 0;
    generatePermutations(nums, numsSize, 0, res, returnSize);
    
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    
    return res;
}
