#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    long long maximumStrength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        // Max-heap to store the top k subarray sums with their starting indices
        priority_queue<pair<long long, int>> maxHeap;

        // DP array to store the maximum strength after selecting some subarrays
        vector<long long> dp(n + 1, LLONG_MIN);
        dp[0] = 0;  // No subarrays, no strength

        // Loop over each number of subarrays from 1 to k
        for (int j = 1; j <= k; ++j) {
            // New DP array for current number of subarrays
            vector<long long> newDp(n + 1, LLONG_MIN);
            priority_queue<pair<long long, int>> newMaxHeap;
            
            for (int i = j; i <= n; ++i) {
                // Calculate maximum strength ending at i with j subarrays
                while (!maxHeap.empty() && maxHeap.top().second < i) {
                    newDp[i] = max(newDp[i], dp[maxHeap.top().second] + prefixSum[i] - prefixSum[maxHeap.top().second]);
                    maxHeap.pop();
                }

                // Push the current value for consideration for next i's
                maxHeap.push(make_pair(dp[i] - prefixSum[i], i));

                // Maintain the state to the next j loop
                if (newDp[i] != LLONG_MIN) {
                    newMaxHeap.push(make_pair(newDp[i] + prefixSum[i], i));
                }
            }

            // Copy the new dp to dp
            dp = newDp;
            maxHeap = newMaxHeap;
        }

        // The answer is the maximum strength that can be achieved with exactly k subarrays
        return dp[n];
    }
};
