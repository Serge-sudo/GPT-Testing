#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        const int MOD = 1000000007;
        int n = nums.size();
        int result = 0;
        
        // dp[j] will store the number of ways to get sum j using any subsequence
        vector<int> dp(k + 1, 0);
        dp[0] = 1; // Base case: one way to make sum 0 (empty subsequence)
        
        for (int num : nums) {
            // Update the dp array for the current number in reverse
            for (int j = k; j >= num; j--) {
                dp[j] = (dp[j] + dp[j - num]) % MOD;
            }
        }
        
        return dp[k];
    }
};
