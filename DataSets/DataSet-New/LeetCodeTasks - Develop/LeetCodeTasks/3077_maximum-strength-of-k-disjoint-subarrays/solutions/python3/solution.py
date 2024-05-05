from typing import List
from functools import lru_cache

class Solution:
    def maximumStrength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        prefix_sums = [0] * (n + 1)
        
        # Compute prefix sums
        for i in range(n):
            prefix_sums[i + 1] = prefix_sums[i] + nums[i]

        # Helper function to calculate sum of a subarray nums[l..r]
        def subarray_sum(l, r):
            return prefix_sums[r + 1] - prefix_sums[l]
        
        # Memoization for dynamic programming
        @lru_cache(None)
        def dp(i, rem_k):
            if rem_k == 0:
                return 0
            if i >= n:
                return float('-inf')
            
            max_strength = float('-inf')
            # Choose a subarray starting at index i
            for j in range(i, n):
                subarray_strength = subarray_sum(i, j)
                next_strength = dp(j + 1, rem_k - 1)
                # Calculate strength with current subarray included
                if next_strength != float('-inf'):
                    current_strength = (rem_k - (rem_k - 1)) * subarray_strength + next_strength
                    max_strength = max(max_strength, current_strength)
            return max_strength
        
        # Initialize dynamic programming approach starting from index 0 with k subarrays remaining
        return dp(0, k)
