from typing import List

class Solution:
    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:
        n = len(nums)
        prefix_sum = [0] * (n + 1)
        for i in range(n):
            prefix_sum[i + 1] = prefix_sum[i] + nums[i]
        
        dp = [float('inf')] * n
        for i in range(k - 1, n):
            dp[i] = prefix_sum[i + 1]
            for j in range(i - dist, max(-1, i - k), -1):
                dp[i] = min(dp[i], prefix_sum[i + 1] - prefix_sum[j + 1] + dp[j])
        
        return dp[-1]
