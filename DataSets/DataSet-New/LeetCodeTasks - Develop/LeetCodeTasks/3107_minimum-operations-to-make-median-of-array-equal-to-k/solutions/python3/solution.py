class Solution:
    def minOperationsToMakeMedianK(self, nums: list[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        if n % 2 == 1:
            median_index = n // 2
        else:
            median_index = n // 2  # In Python, indexing is 0-based, so this already gives the larger of the two middle indices.
        
        return abs(nums[median_index] - k)
