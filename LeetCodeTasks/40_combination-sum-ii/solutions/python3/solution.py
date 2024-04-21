from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def backtrack(start, target, current):
            if target == 0:
                result.append(current.copy())
                return
            if target < 0:
                return

            prev = -1
            for i in range(start, len(candidates)):
                if candidates[i] == prev:
                    continue
                current.append(candidates[i])
                backtrack(i + 1, target - candidates[i], current)
                current.pop()
                prev = candidates[i]

        candidates.sort()
        result = []
        backtrack(0, target, [])
        return result
