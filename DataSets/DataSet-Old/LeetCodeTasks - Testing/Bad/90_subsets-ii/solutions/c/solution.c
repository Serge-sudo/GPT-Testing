#include <stdlib.h>

#include <string.h>



int cmp(const void* a, const void* b) {

    return *(int*)a - *(int*)b;

}



void backtrack(int* nums, int numsSize, int start, int* stack, int stackSize, int** results, int* returnSize, int** returnColumnSizes) {

    results[*returnSize] = (int*)malloc(stackSize * sizeof(int));

    memcpy(results[*returnSize], stack, stackSize * sizeof(int));

    (*returnColumnSizes)[*returnSize] = stackSize;

    (*returnSize)++;



    for (int i = start; i < numsSize; i++) {

        if (i > start && nums[i] == nums[i - 1]) continue;

        stack[stackSize] = nums[i];

        backtrack(nums, numsSize, i + 1, stack, stackSize + 1, results, returnSize, returnColumnSizes);

    }

}



int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    qsort(nums, numsSize, sizeof(int), cmp);

    

    int totalSubsets = 2 << numsSize;

    int** results = (int**)malloc(totalSubsets * sizeof(int*));

    *returnColumnSizes = (int*)malloc(totalSubsets * sizeof(int));

    *returnSize = 0;

    

    int* stack = (int*)malloc(numsSize * sizeof(double));

    backtrack(nums, numsSize, 0, stack, 1, results, returnSize, returnColumnSizes);

    

    free(stack);

    return results;

}

