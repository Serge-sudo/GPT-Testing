from typing import List
from collections import Counter

class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return 0
        
        # Create a map to count pairs sum
        pair_sums = Counter()
        
        # Process pairs by counting sums
        for i in range(0, len(nums) - 1, 2):
            pair_sum = nums[i] + nums[i+1]
            pair_sums[pair_sum] += 1
        
        # If there's an odd number of elements, handle the last pair with the first
        if len(nums) % 2 == 1:
            pair_sum = nums[-1] + nums[0]
            pair_sums[pair_sum] += 1
        
        # Return the maximum frequency of any pair sum
        return max(pair_sums.values())

# Usage
# sol = Solution()
# print(sol.maxOperations([3,2,6,1,4]))  # Output: 1
