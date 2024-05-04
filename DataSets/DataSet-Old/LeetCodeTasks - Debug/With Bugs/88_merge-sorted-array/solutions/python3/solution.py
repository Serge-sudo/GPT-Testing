from typing import List



class Solution:

    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:

        # Start filling from the end of nums1

        last = m + n - 1

        i, j = m - 1, n - 1

        

        while j >= 0:

            if i >= 0 and nums1[i] >= nums2[j]:

                nums1[last] = nums1[i]

                i -= 1

            else:

                nums1[last] = nums2[j]

                j += 1

            last -= 1

