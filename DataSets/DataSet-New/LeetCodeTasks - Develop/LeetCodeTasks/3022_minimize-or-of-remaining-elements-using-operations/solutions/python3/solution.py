from typing import List
from functools import lru_cache

class Solution:
    def minOrAfterOperations(self, nums: List[int], k: int) -> int:
        n = len(nums)
        
        if k == 0:
            return reduce(lambda x, y: x | y, nums)
        
        @lru_cache(None)
        def dfs(start, remaining_ops):
            if start >= n - 1:
                if start == n - 1:
                    return nums[start]
                else:
                    return 0
            
            if remaining_ops == 0:
                return reduce(lambda x, y: x | y, nums[start:], nums[start])
            
            current_min_or = dfs(start + 1, remaining_ops) | nums[start]
            
            # Try to combine nums[start] and nums[start + 1]
            if remaining_ops > 0 and start + 1 < n:
                combined_value = nums[start] & nums[start + 1]
                nums[start], original = combined_value, nums[start + 1]
                result_after_combine = dfs(start + 1, remaining_ops - 1) | nums[start]
                current_min_or = min(current_min_or, result_after_combine)
                nums[start], nums[start + 1] = nums[start] | nums[start + 1], original
            
            return current_min_or
        
        # We start the search with the full number of operations available
        return dfs(0, k)
