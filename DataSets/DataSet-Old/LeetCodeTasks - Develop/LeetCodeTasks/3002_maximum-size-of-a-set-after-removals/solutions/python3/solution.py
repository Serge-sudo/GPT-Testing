from typing import List
from collections import Counter

class Solution:
    def maximumSetSize(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        half_n = n // 2
        
        # Count frequency of each number in both arrays
        count1 = Counter(nums1)
        count2 = Counter(nums2)
        
        # List of tuples (number, minimum occurrences in both arrays)
        elements = []
        for num in set(nums1 + nums2):
            elements.append((num, min(count1.get(num, 0), count2.get(num, 0))))
        
        # Sort based on the number of times we can definitely include them in the set,
        # more times first as they have lower cost in terms of reducing the size of the set
        elements.sort(key=lambda x: -x[1])
        
        # We need to balance between keeping duplicates from being over-removed
        # and maximizing the set size by including as many unique elements as possible
        remaining_removals1 = half_n
        remaining_removals2 = half_n
        set_size = 0
        
        for num, min_occur in elements:
            if remaining_removals1 == 0 or remaining_removals2 == 0:
                break
            # The number of this element we can keep is at least the minimum of what's present
            # in both arrays minus how many we can afford to remove.
            max_keep1 = max(0, count1.get(num, 0) - remaining_removals1)
            max_keep2 = max(0, count2.get(num, 0) - remaining_removals2)
            
            # We include this number in the set if we can keep at least one in any of the arrays
            if max_keep1 > 0 or max_keep2 > 0:
                set_size += 1
                # Calculate how many we need to remove to achieve this state
                to_remove1 = count1.get(num, 0) - max_keep1
                to_remove2 = count2.get(num, 0) - max_keep2
                # Reduce the number of remaining removals
                remaining_removals1 -= to_remove1
                remaining_removals2 -= to_remove2
        
        return set_size
