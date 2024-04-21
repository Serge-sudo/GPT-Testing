from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 0  # Position to place the next allowable element
        for num in nums:
            # Allow placement if we're filling the first two spots
            # or if the current number is different from the last two allowed numbers
            if k < 2 or num != nums[k - 2]:
                nums[k] = num
                k += 1
        return k
