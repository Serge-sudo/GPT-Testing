#include <limits.h>

int minimumCost(int* nums, int numsSize) {
    // dp[i][j] will store the minimum sum of costs when dividing first i elements into j parts
    int dp[51][4]; // 50 elements and need up to 3 partitions
    
    // Initialize the dp array to a very high value
    for (int i = 0; i <= numsSize; ++i) {
        for (int j = 0; j <= 3; ++j) {
            dp[i][j] = INT_MAX;
        }
    }
    
    // Base case: Cost of dividing 0 elements into 0 parts is 0
    dp[0][0] = 0;
    
    // Fill the dp table
    for (int i = 1; i <= numsSize; ++i) {
        for (int j = 1; j <= 3; ++j) {
            int sum = 0;
            // Try different lengths for the last subarray
            for (int k = i; k >= j; --k) {
                sum += nums[k-1]; // Adding the cost of the subarray that starts at k and ends at i
                // Update dp[i][j] with the minimum value found
                if (dp[k-1][j-1] != INT_MAX) {
                    dp[i][j] = dp[i][j] < (dp[k-1][j-1] + nums[k-1]) ? dp[i][j] : (dp[k-1][j-1] + nums[k-1]);
                }
            }
        }
    }
    
    // The answer will be stored in dp[numsSize][3] - the minimum sum of costs when the whole array is divided into 3 parts
    return dp[numsSize][3];
}
