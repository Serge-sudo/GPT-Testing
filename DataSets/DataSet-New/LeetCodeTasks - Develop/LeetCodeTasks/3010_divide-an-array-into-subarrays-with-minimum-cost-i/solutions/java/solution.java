class Solution {
    public int minimumCost(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n][4]; // dp[i][j] is the minimum cost to split first i elements into j subarrays
        
        // Initialize dp
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        
        // Initial case: the minimum cost to form 1 subarray up to index i is just the first element of nums
        dp[0][1] = nums[0];
        
        // Fill dp for 1 subarray
        for (int i = 1; i < n; i++) {
            dp[i][1] = nums[0]; // The cost of one subarray from 0 to i is just the first element
        }
        
        // Fill dp table
        for (int j = 2; j <= 3; j++) { // We need 3 subarrays
            for (int i = j - 1; i < n; i++) {
                if (j == 1) {
                    dp[i][j] = nums[0]; // Only one subarray means taking the entire array
                } else {
                    for (int k = j - 2; k < i; k++) {
                        dp[i][j] = Math.min(dp[i][j], dp[k][j - 1] + nums[k + 1]);
                    }
                }
            }
        }
        
        return dp[n - 1][3];
    }
}
