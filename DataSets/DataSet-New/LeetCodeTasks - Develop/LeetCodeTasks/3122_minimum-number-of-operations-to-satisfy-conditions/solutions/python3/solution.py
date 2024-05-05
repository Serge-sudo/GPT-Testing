from typing import List

class Solution:
    def minimumOperations(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        operations = 0

        # Make columns consistent
        for j in range(n):
            for i in range(m - 1):
                if grid[i][j] != grid[i + 1][j]:
                    operations += 1
                    grid[i + 1][j] = grid[i][j]

        # Make rows have distinct consecutive elements
        for i in range(m):
            for j in range(n - 1):
                if grid[i][j] == grid[i][j + 1]:
                    operations += 1
                    # Find a new value different from adjacent cells
                    new_value = (grid[i][j] + 1) % 10
                    while (j > 0 and new_value == grid[i][j - 1]) or (new_value == grid[i][j + 1]):
                        new_value = (new_value + 1) % 10
                    grid[i][j + 1] = new_value

        return operations
