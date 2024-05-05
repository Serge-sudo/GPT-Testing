class Solution:
    def resultArray(self, nums: list[int]) -> list[int]:
        if not nums:
            return []
        
        arr1 = []
        arr2 = []
        
        # First two operations are predefined
        arr1.append(nums[0])
        if len(nums) > 1:
            arr2.append(nums[1])
        
        # Process further elements
        for i in range(2, len(nums)):
            if arr1[-1] > arr2[-1]:
                arr1.append(nums[i])
            else:
                arr2.append(nums[i])
        
        # Concatenate arr1 and arr2 to form result
        result = arr1 + arr2
        return result
