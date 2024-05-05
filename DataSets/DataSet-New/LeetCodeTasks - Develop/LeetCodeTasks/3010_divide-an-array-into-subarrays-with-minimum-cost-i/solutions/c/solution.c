#include <limits.h>

int minimumCost(int* nums, int numsSize) {
    // Initialize a large enough value for comparison
    int minSum = INT_MAX;
    
    // We need to choose two breakpoints for the array to split it into three parts
    for (int i = 1; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            // Calculate the sum of costs of the three subarrays
            int currentSum = nums[0] + nums[i] + nums[j];
            // Update minSum if the current sum of costs is lower
            if (currentSum < minSum) {
                minSum = currentSum;
            }
        }
    }
    
    return minSum;
}
