from typing import List
from collections import Counter

class Solution:
    def minimumAddedInteger(self, nums1: List[int], nums2: List[int]) -> int:
        nums2_count = Counter(nums2)
        n = len(nums1)
        min_x = float('inf')
        
        # Try every possible pair to remove from nums1
        for i in range(n):
            for j in range(i + 1, n):
                # Calculate the transformed nums1 without the two selected elements
                transformed = nums1[:i] + nums1[i+1:j] + nums1[j+1:]
                # Attempt to calculate x based on each element matching to nums2
                for k in transformed:
                    for m in nums2:
                        x = m - k
                        # Calculate the new list after applying x
                        new_nums1 = [item + x for item in transformed]
                        if Counter(new_nums1) == nums2_count:
                            min_x = min(min_x, x)
        return min_x
