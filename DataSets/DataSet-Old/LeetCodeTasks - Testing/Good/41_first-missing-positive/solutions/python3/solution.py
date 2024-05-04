class Solution:
    def firstMissingPositive(self, nums: list[int]) -> int:
        n = len(nums)
        
        # Make all numbers in the array positive and ignore those > n
        for i in range(n):
            if nums[i] <= 0 or nums[i] > n:
                nums[i] = n + 1
        
        # Use the index as a hash to record the presence of numbers
        for num in nums:
            index = abs(num) - 1
            if index < n:
                nums[index] = -abs(nums[index])
        
        # The first index which is positive, its 1-based index is the answer
        for i in range(n):
            if nums[i] > 0:
                return i + 1
        
        # If no missing numbers are found in the range [1, n]
        return n + 1
