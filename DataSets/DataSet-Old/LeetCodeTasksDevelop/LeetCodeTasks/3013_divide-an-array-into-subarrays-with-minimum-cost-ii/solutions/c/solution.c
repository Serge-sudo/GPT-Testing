#include <limits.h>

long long minimumCost(int* nums, int numsSize, int k, int dist) {
    long long dp[numsSize];
    long long minCost = LLONG_MAX;

    for (int i = 0; i < numsSize; i++) {
        dp[i] = nums[i];
        for (int j = 1; j < k && i - j * dist >= 0; j++) {
            dp[i] = fmin(dp[i], dp[i - j * dist] + nums[i]);
        }
        if (i >= (k - 1) * dist) {
            minCost = fmin(minCost, dp[i]);
        }
    }
    return minCost;
}
