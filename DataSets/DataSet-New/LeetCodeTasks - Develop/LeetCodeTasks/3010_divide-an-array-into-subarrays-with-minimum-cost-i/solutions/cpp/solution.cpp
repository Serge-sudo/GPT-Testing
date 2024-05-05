#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(4, INT_MAX));
        dp[0][0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, 3); ++j) {
                for (int k = j - 1; k < i; ++k) {
                    dp[i][j] = min(dp[i][j], dp[k][j - 1] + nums[k]);
                }
            }
        }

        return dp[n][3];
    }
};
