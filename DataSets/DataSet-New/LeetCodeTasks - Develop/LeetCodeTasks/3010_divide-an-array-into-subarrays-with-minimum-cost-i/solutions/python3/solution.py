from typing import List
from functools import lru_cache

class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        n = len(nums)

        @lru_cache(None)
        def dp(i, k):
            # i is the starting index for forming subarrays
            # k is the number of subarrays left to form
            if k == 1:  # only one subarray left, take the rest as one subarray
                return nums[i]
            if i >= n:
                return float('inf')
            
            min_cost = float('inf')
            # Try all possible next splits
            for j in range(i + 1, n):
                # nums[i] is the cost of the subarray starting at i and ending before j
                # Calculate remaining cost from index j with k-1 subarrays left
                min_cost = min(min_cost, nums[i] + dp(j, k - 1))
            
            return min_cost
        
        # Start from index 0 to form 3 subarrays
        return dp(0, 3)
