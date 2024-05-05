from typing import List

class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        min_length = float('inf')
        
        for start in range(n):
            or_value = 0
            for end in range(start, n):
                or_value |= nums[end]
                if or_value >= k:
                    min_length = min(min_length, end - start + 1)
                    break
        
        return min_length if min_length != float('inf') else -1
