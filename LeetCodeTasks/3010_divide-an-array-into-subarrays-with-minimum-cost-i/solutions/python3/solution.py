from typing import List

class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        n = len(nums)
        # Initialize dp table with infinity, dp[i][j] means the minimum cost to divide the first i elements into j parts
        dp = [[float('inf')] * 4 for _ in range(n+1)]
        # Base case: No cost to split zero elements into zero parts
        dp[0][0] = 0
        
        # Fill the dp table
        for i in range(1, n + 1):
            for j in range(1, 4):
                for k in range(i):
                    # Update dp[i][j] considering splitting at k
                    dp[i][j] = min(dp[i][j], dp[k][j-1] + nums[k])
        
        # The answer is the minimum cost to divide all n elements into 3 parts
        return dp[n][3]
