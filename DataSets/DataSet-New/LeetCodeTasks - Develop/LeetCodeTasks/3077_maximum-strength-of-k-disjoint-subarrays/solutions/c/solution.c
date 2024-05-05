#include <limits.h>

long long maximumStrength(int* nums, int numsSize, int k) {
    // Helper function to calculate maximum subarray sum using Kadane's algorithm
    long long maxSubarraySum(int* nums, int numsSize) {
        long long maxSum = LLONG_MIN, currentSum = 0;
        for (int i = 0; i < numsSize; i++) {
            currentSum += nums[i];
            if (currentSum > maxSum) maxSum = currentSum;
            if (currentSum < 0) currentSum = 0;
        }
        return maxSum;
    }
    
    // Dynamic programming tables
    long long dp[k+1][numsSize+1];
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= numsSize; j++) {
            dp[i][j] = LLONG_MIN;
        }
    }
    
    dp[0][0] = 0; // Base case: 0 subarrays taken up to the first 0 elements
    
    // Fill the dp table
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= numsSize; j++) {
            long long sum = 0;
            for (int m = j; m >= 0; m--) {
                // Calculate the sum of current subarray from m to j-1
                sum += (m < j) ? nums[m] : 0;
                
                // Update the dp value for using i subarrays ending at position j
                if (m > 0 && dp[i-1][m-1] != LLONG_MIN) {
                    long long currentStrength = dp[i-1][m-1] + sum * (i % 2 ? 1 : -1);
                    if (currentStrength > dp[i][j]) {
                        dp[i][j] = currentStrength;
                    }
                }
            }
        }
    }
    
    // The answer is in dp[k][numsSize], taking k subarrays using all numsSize elements
    return dp[k][numsSize];
}
