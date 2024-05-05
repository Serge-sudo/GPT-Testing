from typing import List

class Solution:
    def numberOfSubarrays(self, nums: List[int]) -> int:
        count = 0
        n = len(nums)
        
        # Track the start and end indices of each unique value
        indices = {}
        
        for i, num in enumerate(nums):
            if num not in indices:
                indices[num] = [i, i]
            else:
                indices[num][1] = i
        
        # Compute the number of subarrays for each number
        for num, (start, end) in indices.items():
            if start != end:
                count += (start + 1) * (n - end)
        
        return count
