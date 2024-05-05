from typing import List

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        results = []
        
        def backtrack(combination, counter):
            if len(combination) == len(nums):
                results.append(combination[:])
                return
            
            for num in counter:
                if counter[num] > 0:
                    combination.append(num)
                    counter[num] -= 1
                    
                    backtrack(combination, counter)
                    
                    combination.pop()
                    counter[num] += 1
        
        counter = {}
        for num in nums:
            if num in counter:
                counter[num] += 1
            else:
                counter[num] = 1
        
        backtrack([], counter)
        return results
