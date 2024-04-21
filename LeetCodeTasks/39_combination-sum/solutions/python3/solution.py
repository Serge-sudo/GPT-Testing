from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        results = []
        
        def backtrack(start, combination, current_sum):
            if current_sum == target:
                results.append(list(combination))
                return
            if current_sum > target:
                return
            
            for i in range(start, len(candidates)):
                combination.append(candidates[i])
                backtrack(i, combination, current_sum + candidates[i])
                combination.pop()
        
        backtrack(0, [], 0)
        return results
