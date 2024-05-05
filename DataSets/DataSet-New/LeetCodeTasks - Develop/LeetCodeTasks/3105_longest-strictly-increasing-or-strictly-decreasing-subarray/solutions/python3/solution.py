from typing import List

class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        max_len = 0
        current_len = 1
        
        # Check for strictly increasing subarray
        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]:
                current_len += 1
            else:
                max_len = max(max_len, current_len)
                current_len = 1
        max_len = max(max_len, current_len)
        
        # Check for strictly decreasing subarray
        current_len = 1
        for i in range(1, len(nums)):
            if nums[i] < nums[i-1]:
                current_len += 1
            else:
                max_len = max(max_len, current_len)
                current_len = 1
        max_len = max(max_len, current_len)
        
        return max_len
