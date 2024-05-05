import java.util.Arrays;

class Solution {
    public int sumOfPower(int[] nums, int k) {
        final int MOD = 1000000007;
        int n = nums.length;
        int[] dp = new int[k + 1]; // dp[j] will be the number of ways to get sum j using any subset of nums.
        dp[0] = 1; // Base case: one way to get sum 0, use the empty set.

        for (int num : nums) {
            for (int j = k; j >= num; j--) {
                dp[j] = (dp[j] + dp[j - num]) % MOD;
            }
        }
        
        return dp[k];
    }
}
