class Solution {
    public int minimumCost(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n][4];
        final int INF = Integer.MAX_VALUE / 2; // Use a large value to represent infeasible splits

        // Initialize DP table
        for (int i = 0; i < n; ++i) {
            for (int k = 1; k <= 3; ++k) {
                dp[i][k] = INF;
            }
        }

        // Base case: the first element starts the first group
        dp[0][1] = nums[0];

        // Fill the DP table
        for (int i = 1; i < n; ++i) {
            for (int k = 1; k <= 3; ++k) {
                // Continue the current group
                if (k > 1 && i >= k) {
                    dp[i][k] = Math.min(dp[i][k], dp[i-1][k] + nums[i]);
                }
                // Start a new group
                if (k > 1 && dp[i-1][k-1] != INF) {
                    dp[i][k] = Math.min(dp[i][k], dp[i-1][k-1] + nums[i]);
                }
            }
        }

        // The answer is at the last element with exactly 3 groups formed
        return dp[n-1][3];
    }
}
