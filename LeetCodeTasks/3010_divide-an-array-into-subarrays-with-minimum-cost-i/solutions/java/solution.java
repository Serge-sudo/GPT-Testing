class Solution {
    public int minimumCost(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n+1][4]; // dp[i][j] represents the minimum cost of splitting the first i elements into j subarrays

        // Initialize dp array with a large number to represent unachievable states
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 4; j++) {
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        
        dp[0][0] = 0; // Cost of forming 0 parts from 0 elements is 0

        // Iterate over every position in the array
        for (int i = 1; i <= n; i++) {
            // Iterate for parts from 1 to 3
            for (int j = 1; j <= 3; j++) {
                // Try every possible end for the (j-1)th subarray
                for (int k = j - 1; k < i; k++) {
                    // If previous state is valid and current state can be updated to a lower cost
                    if (dp[k][j-1] != Integer.MAX_VALUE) {
                        dp[i][j] = Math.min(dp[i][j], dp[k][j-1] + nums[k]);
                    }
                }
            }
        }

        return dp[n][3]; // The minimum cost to split all elements into 3 parts
    }
}
