#include <stdlib.h>

long long minOperationsToMakeMedianK(int* nums, int numsSize, int k) {
    long long operations = 0;
    int medianIndex = numsSize / 2;
    
    // Sort the array to find the current median
    qsort(nums, numsSize, sizeof(int), (int (*)(const void*, const void*))strcmp);
    
    // Calculate the minimum operations needed
    for (int i = 0; i <= medianIndex; ++i) {
        operations += labs(nums[i] - k);
    }
    
    return operations;
}
