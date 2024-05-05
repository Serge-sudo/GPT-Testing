from typing import List

class Solution:
    def minimumValueSum(self, nums: List[int], andValues: List[int]) -> int:
        n, m = len(nums), len(andValues)
        inf = float('inf')
        
        # dp[i][j] means the minimum sum of values we can get by dividing first i numbers into j subarrays
        dp = [[inf] * (m + 1) for _ in range(n + 1)]
        dp[0][0] = 0
        
        for j in range(1, m + 1):
            for i in range(j, n + 1):
                current_and = nums[i - 1]
                for k in range(i, j - 1, -1):  # iterate backward
                    current_and &= nums[k - 1]
                    if current_and == andValues[j - 1]:
                        if dp[k - 1][j - 1] != inf:
                            dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + nums[i - 1])
        
        return dp[n][m] if dp[n][m] != inf else -1
