from typing import List

class Solution:
    def countOfPairs(self, n: int, x: int, y: int) -> List[int]:
        result = [0] * n
        distances = [0] * (n - 1)
        
        for i in range(1, n + 1):
            for j in range(i + 1, n + 1):
                distance = min(abs(i - j), abs(i - x) + abs(j - y) + 1, abs(i - y) + abs(j - x) + 1)
                result[distance - 1] += 1
        
        return result
