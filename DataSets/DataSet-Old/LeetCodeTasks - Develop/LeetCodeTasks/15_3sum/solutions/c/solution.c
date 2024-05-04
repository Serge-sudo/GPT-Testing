#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    *returnSize = 0;
    int** results = malloc(sizeof(int*) * (numsSize * numsSize));

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicate values
        int left = i + 1, right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                results[*returnSize] = malloc(sizeof(int) * 3);
                results[*returnSize][0] = nums[i];
                results[*returnSize][1] = nums[left];
                results[*returnSize][2] = nums[right];
                (*returnSize)++;

                while (left < right && nums[left] == nums[left + 1]) left++; // Skip duplicate values
                while (left < right && nums[right] == nums[right - 1]) right--; // Skip duplicate values
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 3;
    }

    return results;
}
