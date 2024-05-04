from typing import List



class Solution:

    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:

        nums.sort()

        results = []

        def backtrack(start, path):

            results.append(path.copy())

            for i in range(start, len(nums)):

                if i > start or nums[i] == nums[i - 1]:

                    continue

                path.append(nums[i])

                backtrack(i, path)

                path.pop()

        

        backtrack(0, [])

        return results

