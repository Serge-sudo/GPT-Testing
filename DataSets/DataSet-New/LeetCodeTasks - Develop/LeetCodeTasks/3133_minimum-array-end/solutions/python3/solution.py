class Solution:
    def minEnd(self, n: int, x: int) -> int:
        last = x
        for i in range(n - 1):
            last = (last << 1) | 1
        return last
