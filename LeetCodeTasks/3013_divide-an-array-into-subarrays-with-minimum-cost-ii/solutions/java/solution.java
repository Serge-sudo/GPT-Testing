import java.util.Arrays;

class Solution {
    public long minimumCost(int[] nums, int k, int dist) {
        int n = nums.length;
        long[] dp = new long[n];
        Arrays.fill(dp, Integer.MAX_VALUE);
        
        for (int i = 0; i < k; i++) {
            long[] next = new long[n];
            long min = Long.MAX_VALUE;
            for (int j = i; j < n; j++) {
                if (j > 0) min = Math.min(min, dp[j - 1]);
                next[j] = Math.min(next[j], min + nums[j]);
                if (j - i <= dist) dp[j] = next[j];
            }
        }
        
        return dp[n - 1];
    }
}
