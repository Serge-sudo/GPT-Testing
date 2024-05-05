class Solution:
    def sumOfPower(self, nums: list[int], k: int) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        # dp[j] will store the number of ways to get sum j using any number of elements
        dp = [0] * (k + 1)
        dp[0] = 1  # There's one way to make sum 0 - use no elements
        
        for num in nums:
            # Update dp array backwards for each number
            for j in range(k, num - 1, -1):
                dp[j] = (dp[j] + dp[j - num]) % MOD
        
        return dp[k]
