from typing import List

class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        def greaterCount(arr, val):
            return sum(1 for x in arr if x > val)

        arr1 = []
        arr2 = []
        
        # First element to arr1, second element to arr2
        arr1.append(nums[0])
        if len(nums) > 1:
            arr2.append(nums[1])
        
        for i in range(2, len(nums)):
            num = nums[i]
            count1 = greaterCount(arr1, num)
            count2 = greaterCount(arr2, num)
            
            if count1 > count2:
                arr1.append(num)
            elif count1 < count2:
                arr2.append(num)
            else:
                # Counts are equal, decide based on length or default to arr1
                if len(arr1) < len(arr2):
                    arr1.append(num)
                else:
                    arr2.append(num)

        return arr1 + arr2
