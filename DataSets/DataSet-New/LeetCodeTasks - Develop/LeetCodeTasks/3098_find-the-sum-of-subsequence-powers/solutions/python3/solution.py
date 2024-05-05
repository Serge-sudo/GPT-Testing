from itertools import combinations

class Solution:
    def sumOfPowers(self, nums: list[int], k: int) -> int:
        MOD = 10**9 + 7
        nums.sort()
        n = len(nums)
        result = 0
        
        for combo in combinations(nums, k):
            # Minimum absolute difference in this subsequence
            min_diff = min(abs(combo[i] - combo[i-1]) for i in range(1, k))
            result = (result + min_diff) % MOD
            
        return result
