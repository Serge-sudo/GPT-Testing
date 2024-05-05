from typing import List

class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        if k == 0:
            return 1  # The OR of any non-zero number is non-zero, which is >= 0
        
        min_length = float('inf')
        current_or = 0
        start = 0
        
        for end in range(len(nums)):
            current_or |= nums[end]
            # When current OR meets the requirement
            while current_or >= k:
                min_length = min(min_length, end - start + 1)
                current_or ^= nums[start]  # Remove the start element from OR
                start += 1
                # Recalculate OR for the new window
                current_or = 0
                for i in range(start, end + 1):
                    current_or |= nums[i]
        
        return min_length if min_length != float('inf') else -1
