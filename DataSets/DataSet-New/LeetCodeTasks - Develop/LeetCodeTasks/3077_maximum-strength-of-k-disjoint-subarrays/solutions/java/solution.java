class Solution {
    public long maximumStrength(int[] nums, int k) {
        int n = nums.length;
        long[] prefixSums = new long[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }

        // dp[i][j] will store the maximum strength using exactly j subarrays from first i elements
        long[][] dp = new long[n + 1][k + 1];
        
        // Initialize dp array for the case of using 0 subarrays (strength is 0)
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = Long.MIN_VALUE;
            }
        }
        dp[0][0] = 0; // No subarrays, no elements, strength 0

        // Fill dp array
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= Math.min(i, k); j++) {
                // We can only form j subarrays using at least j elements
                for (int m = 0; m < i; m++) {  // m is the starting index of the new subarray, m < i
                    long subarraySum = prefixSums[i] - prefixSums[m];
                    long weight = ((j % 2 == 1) ? 1 : -1) * (k - j + 1);
                    dp[i][j] = Math.max(dp[i][j], dp[m][j - 1] + weight * subarraySum);
                }
            }
        }

        return dp[n][k];
    }
}
