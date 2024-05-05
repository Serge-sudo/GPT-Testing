from typing import List

class Solution:
    def numberOfRightTriangles(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        
        # Compute counts of 1's in each row and each column
        rowCount = [sum(row) for row in grid]
        colCount = [sum(grid[i][j] for i in range(rows)) for j in range(cols)]
        
        # Count the number of right triangles
        triangles = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    # Only if there is a '1' at the current position
                    # (i, j) can be the right-angle vertex of a triangle
                    triangles += (rowCount[i] - 1) * (colCount[j] - 1)
        
        return triangles
