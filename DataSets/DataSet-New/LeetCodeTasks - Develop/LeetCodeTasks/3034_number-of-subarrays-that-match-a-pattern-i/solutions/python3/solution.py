from typing import List

class Solution:
    def countMatchingSubarrays(self, nums: List[int], pattern: List[int]) -> int:
        n = len(nums)
        m = len(pattern)
        count = 0
        
        for i in range(n - m):
            match = True
            for k in range(m):
                if (pattern[k] == 1 and not (nums[i + k] < nums[i + k + 1])) or \
                   (pattern[k] == 0 and not (nums[i + k] == nums[i + k + 1])) or \
                   (pattern[k] == -1 and not (nums[i + k] > nums[i + k + 1])):
                    match = False
                    break
            if match:
                count += 1
        
        return count
