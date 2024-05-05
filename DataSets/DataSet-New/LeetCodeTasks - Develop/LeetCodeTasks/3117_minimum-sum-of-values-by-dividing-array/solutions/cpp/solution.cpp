#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

using namespace std;

class Solution {
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n = nums.size();
        int m = andValues.size();
        vector<vector<long long>> dp(m, vector<long long>(n, LLONG_MAX));
        
        // Initialize the first row of the DP table.
        int currentAnd = 0;
        for (int j = 0; j < n; ++j) {
            currentAnd &= nums[j];
            if (currentAnd == andValues[0]) {
                dp[0][j] = nums[j];
            }
        }
        
        // Fill the DP table for the rest of the subarrays
        for (int i = 1; i < m; ++i) {
            currentAnd = 0;
            for (int j = i; j < n; ++j) {
                currentAnd = nums[j];
                for (int k = j; k >= i; --k) {
                    currentAnd &= nums[k];
                    if (currentAnd == andValues[i] && dp[i-1][k-1] != LLONG_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i-1][k-1] + nums[j]);
                    }
                }
            }
        }
        
        long long answer = *min_element(dp[m-1].begin(), dp[m-1].end());
        return answer == LLONG_MAX ? -1 : answer;
    }
};
