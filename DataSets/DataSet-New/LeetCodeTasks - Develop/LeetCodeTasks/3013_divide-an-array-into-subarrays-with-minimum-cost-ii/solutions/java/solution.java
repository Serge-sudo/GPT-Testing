import java.util.Arrays;

class Solution {
    public long minimumCost(int[] nums, int k, int dist) {
        int n = nums.length;
        long[][] dp = new long[k][n];
        long[] prefixSum = new long[n + 1];
        
        // Compute prefix sums for efficient range sum calculation
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        // Base case initialization: the cost of using the first subarray ending at each position
        for (int j = 0; j < n; j++) {
            dp[0][j] = nums[0];
        }
        
        // Fill dp table
        for (int i = 1; i < k; i++) {
            // deque to maintain the minimum values in a sliding window
            Deque<Integer> deque = new LinkedList<>();
            deque.add(i - 1);
            
            for (int j = i; j < n; j++) {
                // Ensure the deque only has relevant indices for the current dp row computation
                while (!deque.isEmpty() && deque.peekFirst() < j - dist - 1) {
                    deque.pollFirst();
                }
                
                // Compute dp[i][j]
                dp[i][j] = dp[i - 1][deque.peekFirst()] + nums[j];
                
                // Update deque to maintain the minimum dp value in the current valid range
                while (!deque.isEmpty() && dp[i - 1][deque.peekLast()] >= dp[i - 1][j]) {
                    deque.pollLast();
                }
                deque.add(j);
                
                // Move to the next j
            }
        }
        
        // Find minimum cost of forming k subarrays
        long minCost = Long.MAX_VALUE;
        for (int start = k - 1; start <= n - 1; start++) {
            if (n - start - 1 <= dist) {
                minCost = Math.min(minCost, dp[k - 1][start]);
            }
        }
        
        return minCost;
    }
}
