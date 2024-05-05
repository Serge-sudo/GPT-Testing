class Solution:
    def addedInteger(self, nums1: list[int], nums2: list[int]) -> int:
        # Since nums1[i] + x = nums2[i] for all i, we can calculate x using the first element of each list
        return nums2[0] - nums1[0]
