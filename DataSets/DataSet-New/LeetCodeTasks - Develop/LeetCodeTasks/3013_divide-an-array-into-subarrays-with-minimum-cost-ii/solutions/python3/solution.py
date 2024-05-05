from typing import List
from functools import lru_cache

class Solution:
    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:
        n = len(nums)

        # Use a prefix minimum array to quickly fetch the minimal value in a range
        prefix_min = nums[:]
        for i in range(1, n):
            prefix_min[i] = min(prefix_min[i-1], nums[i])
        
        # A function to get the minimum cost by caching results
        @lru_cache(None)
        def dp(i, remaining_k, first_index):
            if remaining_k == 1:  # Last group takes everything till the end
                return nums[first_index] if i <= first_index <= n-1 else float('inf')
            if i >= n:
                return float('inf')
            
            # Otherwise, try to form the next group
            min_cost = float('inf')
            last_possible_first = min(n - 1, first_index + dist)
            for next_start in range(i + 1, last_possible_first + 2):
                if next_start < n:
                    cost_of_current = nums[first_index]
                    cost_of_next = dp(next_start, remaining_k - 1, next_start)
                    min_cost = min(min_cost, cost_of_current + cost_of_next)
            return min_cost
        
        # Start dp from 0, need to make k subarrays, starting index is 0
        return dp(0, k, 0)
