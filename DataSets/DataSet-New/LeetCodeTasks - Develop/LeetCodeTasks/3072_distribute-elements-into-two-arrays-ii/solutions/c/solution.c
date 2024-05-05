#include <stdlib.h>

int greaterCount(int* arr, int arrSize, int val) {
    int count = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > val) {
            count++;
        }
    }
    return count;
}

int* resultArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));
    if (!result) return NULL;

    // Initially, assume size enough for simplicity of code
    int* arr1 = (int*)malloc(numsSize * sizeof(int));
    int* arr2 = (int*)malloc(numsSize * sizeof(int));

    int size1 = 0, size2 = 0;

    // First two operations
    if (numsSize > 0) {
        arr1[size1++] = nums[0];
    }
    if (numsSize > 1) {
        arr2[size2++] = nums[1];
    }

    // Following operations
    for (int i = 2; i < numsSize; i++) {
        int count1 = greaterCount(arr1, size1, nums[i]);
        int count2 = greaterCount(arr2, size2, nums[i]);

        if (count1 > count2) {
            arr1[size1++] = nums[i];
        } else if (count1 < count2) {
            arr2[size2++] = nums[i];
        } else {
            if (size1 < size2) {
                arr1[size1++] = nums[i];
            } else {
                arr2[size2++] = nums[i];
            }
        }
    }

    // Concatenate results
    for (int i = 0; i < size1; i++) {
        result[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        result[size1 + i] = arr2[i];
    }

    free(arr1);
    free(arr2);

    return result;
}
