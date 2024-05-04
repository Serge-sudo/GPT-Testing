from typing import List

class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        def count_set_bits(num):
            count = 0
            while num:
                count += num & 1
                num >>= 1
            return count
        
        for i in range(len(nums) - 1):
            if count_set_bits(nums[i]) != count_set_bits(nums[i + 1]):
                return False
        return True
