from typing import List

class Solution:
    def countOfPairs(self, n: int, x: int, y: int) -> List[int]:
        result = [0] * n
        for k in range(1, n + 1):
            for i in range(1, n + 1):
                for j in range(1, n + 1):
                    if abs(i - j) + 1 <= k:
                        result[k - 1] += 1
        return result
