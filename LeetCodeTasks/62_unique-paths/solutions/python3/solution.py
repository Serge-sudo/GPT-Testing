class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        from math import comb
        # We need to make m-1 moves down and n-1 moves right, total (m-1) + (n-1) moves
        # The number of unique paths is the combination of (m+n-2) moves taken (m-1) at a time (or (n-1) at a time)
        return comb(m + n - 2, m - 1)
