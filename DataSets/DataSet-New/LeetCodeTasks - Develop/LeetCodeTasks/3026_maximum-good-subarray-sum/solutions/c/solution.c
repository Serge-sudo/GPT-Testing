#include <limits.h>

long long maximumSubarraySum(int* nums, int numsSize, int k) {
    long long maxSum = 0;
    int found = 0;
    
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (abs(nums[i] - nums[j]) == k) {
                long long sum = 0;
                for (int p = i; p <= j; ++p) {
                    sum += nums[p];
                }
                if (!found || sum > maxSum) {
                    maxSum = sum;
                    found = 1;
                }
            }
        }
    }
    
    return found ? maxSum : 0;
}
