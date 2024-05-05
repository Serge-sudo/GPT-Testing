#include <limits.h>

long long minimumCost(int* nums, int numsSize, int k, int dist) {
    // dp[i][j] represents the minimum cost to partition first i elements into j parts
    long long dp[numsSize + 1][k + 1];
    
    // Initialize the dp array with infinity
    for (int i = 0; i <= numsSize; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = LLONG_MAX;
        }
    }
    
    // No cost to partition zero elements into zero parts
    dp[0][0] = 0;
    
    // Fill the dp table
    for (int j = 1; j <= k; j++) {
        for (int i = j; i <= numsSize; i++) {
            if (j == 1) { // The first part must start from the beginning
                dp[i][j] = nums[0];
            } else {
                // We are limiting the end of the (j-1)-th partition
                int limit = (j - 2 + dist < numsSize ? j - 2 + dist : numsSize);
                for (int l = j - 1; l <= i && l <= limit; l++) {
                    if (dp[l][j - 1] != LLONG_MAX) {
                        dp[i][j] = (dp[i][j] < dp[l][j - 1] + nums[l] ? dp[i][j] : dp[l][j - 1] + nums[l]);
                    }
                }
            }
        }
    }
    
    // Get the minimum cost to partition all elements into k parts
    long long minCost = LLONG_MAX;
    for (int i = k; i <= numsSize; i++) {
        if (minCost > dp[i][k]) {
            minCost = dp[i][k];
        }
    }
    
    return minCost;
}
