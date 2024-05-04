#include <vector>
#include <limits>

class Solution {
public:
    int minimumCost(std::vector<int>& nums) {
        int n = nums.size();
        // dp[i][j] means the minimum cost sum to partition the first i elements into j subarrays
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(4, std::numeric_limits<int>::max()));
        dp[0][0] = 0; // cost of zero elements into zero groups is zero

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 3; ++j) {
                // Try every possible subarray ending at 'i' for the j-th subarray
                for (int k = 0; k < i; ++k) {
                    dp[i][j] = std::min(dp[i][j], dp[k][j-1] + nums[k]);
                }
            }
        }

        return dp[n][3];
    }
};
