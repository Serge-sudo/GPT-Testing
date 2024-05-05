from collections import Counter
from typing import List

class Solution:
    def isPossibleToSplit(self, nums: List[int]) -> bool:
        n = len(nums) // 2
        freq = Counter(nums)
        
        # If any number appears more than n times, it is impossible to split
        if any(count > n for count in freq.values()):
            return False
        
        distinct_elements = len(freq)
        
        # We need at least n distinct elements for both halves
        if distinct_elements < n:
            return False
        
        return True
