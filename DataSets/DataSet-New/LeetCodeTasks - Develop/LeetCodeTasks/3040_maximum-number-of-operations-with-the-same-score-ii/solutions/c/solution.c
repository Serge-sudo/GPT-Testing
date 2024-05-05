#include <stdlib.h>

int maxOperations(int* nums, int numsSize) {
    int* pairs = (int*)calloc(2001, sizeof(int)); // Maximum possible sum is 2000 (1000 + 1000)
    int maxOps = 0;

    // Fill in the count for all possible pair sums
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            int sum = nums[i] + nums[j];
            pairs[sum]++;
        }
    }

    // Check the maximum number of same-score operations we can perform
    for (int sum = 2; sum <= 2000; sum++) {
        int operations = pairs[sum];
        if (operations > maxOps) {
            maxOps = operations;
        }
    }

    free(pairs);
    return maxOps;
}
