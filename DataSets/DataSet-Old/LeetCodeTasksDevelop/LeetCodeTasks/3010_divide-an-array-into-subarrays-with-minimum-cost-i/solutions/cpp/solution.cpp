#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minimumCost(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(4, INT_MAX));
        
        // Initialize the dp array for 1 subarray from each point i to n
        for (int i = 0; i < n; ++i) {
            dp[i][1] = nums[i];
        }

        // Fill dp for j = 2 to 3 subarrays
        for (int j = 2; j <= 3; ++j) {
            for (int i = 0; i <= n - j; ++i) {
                for (int k = i + 1; k <= n - j + 1; ++k) {
                    dp[i][j] = std::min(dp[i][j], nums[i] + dp[k][j - 1]);
                }
            }
        }

        // Answer is the minimum cost to split the whole array into 3 subarrays
        return dp[0][3];
    }
};
