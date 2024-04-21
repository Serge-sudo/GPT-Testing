class Solution:
    def sortColors(self, nums: list[int]) -> None:
        # Pointers for next position of 0 and 1
        p0, p1 = 0, 0
        
        # Iterate over the list
        for i in range(len(nums)):
            val = nums[i]
            nums[i] = 2  # We assume the current value is 2
            
            if val < 2:  # This is for 0 or 1
                nums[p1] = 1
                p1 += 1
            
            if val == 0:  # This is specifically for 0
                nums[p0] = 0
                p0 += 1
