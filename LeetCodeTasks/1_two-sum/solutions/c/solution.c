#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Create a structure to store the values and corresponding indices
    typedef struct {
        int value;
        int index;
    } NumIndex;

    NumIndex* elements = (NumIndex*)malloc(sizeof(NumIndex) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        elements[i].value = nums[i];
        elements[i].index = i;
    }

    // Sort the elements array based on the value field
    int compare(const void* a, const void* b) {
        NumIndex* num1 = (NumIndex*)a;
        NumIndex* num2 = (NumIndex*)b;
        return num1->value - num2->value;
    }

    qsort(elements, numsSize, sizeof(NumIndex), compare);

    // Two-pointer technique to find the two numbers that add up to target
    int left = 0;
    int right = numsSize - 1;
    while (left < right) {
        int sum = elements[left].value + elements[right].value;
        if (sum == target) {
            *returnSize = 2;
            int* result = (int*)malloc(sizeof(int) * 2);
            result[0] = elements[left].index;
            result[1] = elements[right].index;
            free(elements);
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    // Free the allocated memory for elements
    free(elements);
    *returnSize = 0;
    return NULL; // This line will never be executed because we assume exactly one solution exists
}
