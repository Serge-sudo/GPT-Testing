#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        vector<vector<long long>> dp(k, vector<long long>(n, LLONG_MAX));
        vector<long long> prefixSum(n + 1, 0);
        
        // Compute prefix sums to speed up range sum calculation
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        // Base case: one partition
        for (int j = 0; j < n; ++j) {
            dp[0][j] = nums[0];
        }

        // Fill dp for all partitions
        for (int p = 1; p < k; ++p) {
            for (int i = p; i < n; ++i) {
                int limit = min(n - k + p + 1, i + dist + 1);
                for (int j = max(p, i - dist); j < limit; ++j) {
                    dp[p][j] = min(dp[p][j], dp[p - 1][i] + nums[j]);
                }
            }
        }

        // Compute the minimum cost from valid partition positions
        long long result = LLONG_MAX;
        int start = max(k - 1, n - dist - 1);
        for (int i = start; i < n; ++i) {
            result = min(result, dp[k - 1][i]);
        }

        return result;
    }
};
