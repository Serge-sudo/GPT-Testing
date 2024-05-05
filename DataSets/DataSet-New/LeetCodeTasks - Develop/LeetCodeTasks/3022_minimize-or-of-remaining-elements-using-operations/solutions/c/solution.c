#include <limits.h>

int minOrAfterOperations(int* nums, int numsSize, int k) {
    if (k == 0) {
        int result = nums[0];
        for (int i = 1; i < numsSize; ++i) {
            result |= nums[i];
        }
        return result;
    }

    // We need to calculate the potential impact of each AND operation
    int minOr = INT_MAX;
    int* temp = (int*)malloc(sizeof(int) * numsSize);
    for (int j = 0; j <= k && j < numsSize - 1; ++j) {
        memcpy(temp, nums, sizeof(int) * numsSize);
        int len = numsSize;
        for (int i = 0; i < j; ++i) {
            temp[i] = temp[i] & temp[i + 1];
            // After each merge operation, we shift elements left by one
            for (int s = i + 1; s < len - 1; ++s) {
                temp[s] = temp[s + 1];
            }
            len--;
        }

        // Calculate OR of the current state of array
        int currentOr = temp[0];
        for (int i = 1; i < len; ++i) {
            currentOr |= temp[i];
        }
        minOr = currentOr < minOr ? currentOr : minOr;
    }
    free(temp);
    return minOr;
}
