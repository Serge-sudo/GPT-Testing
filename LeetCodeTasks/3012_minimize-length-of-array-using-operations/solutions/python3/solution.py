from typing import List

class Solution:
    def minimumArrayLength(self, nums: List[int]) -> int:
        while len(nums) > 1:
            nums.sort()
            if nums[-2] == 0:
                break
            nums.append(nums[-2] % nums[-1])
            nums.pop()
            nums.pop()
        return len(nums)
