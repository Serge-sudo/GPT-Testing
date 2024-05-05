from typing import List

class Solution:
    def countOfPairs(self, n: int, x: int, y: int) -> List[int]:
        if x > y:
            x, y = y, x
        
        # Result list initialized to all zeros
        result = [0] * (n + 1)
        
        # Calculate the minimal distance between all pairs using direct path or via x-y link
        for i in range(1, n + 1):
            for j in range(i + 1, n + 1):
                direct = j - i
                via_xy = abs(x - i) + 1 + abs(j - y)
                if x != y:
                    via_yx = abs(y - i) + 1 + abs(j - x)
                else:
                    via_yx = via_xy  # When x == y, both paths are the same
                
                min_distance = min(direct, via_xy, via_yx)
                result[min_distance] += 2  # count (i, j) and (j, i)
        
        return result[1:]  # Skip index 0 as we want 1-indexed result
