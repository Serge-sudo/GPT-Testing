class Solution:
    def countSubmatrices(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        count = 0

        # Precompute prefix sums for the grid
        prefix_sum = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                prefix_sum[i][j] = grid[i - 1][j - 1] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1]
        
        # Check all submatrices starting from the top-left corner (0,0)
        for r1 in range(m):
            for r2 in range(r1, m):
                for c2 in range(n):
                    submatrix_sum = prefix_sum[r2 + 1][c2 + 1] - prefix_sum[r1][c2 + 1]
                    if submatrix_sum <= k:
                        count += 1

        return count
