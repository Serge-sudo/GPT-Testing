class Solution:
    def canMakeSquare(self, grid: list[list[str]]) -> bool:
        def is_same_color(x, y):
            color = grid[x][y]
            return all(grid[i][j] == color for i in range(x, x + 2) for j in range(y, y + 2))
        
        # Check existing 2x2 squares
        for i in range(2):
            for j in range(2):
                if is_same_color(i, j):
                    return True
        
        # Check potential 2x2 squares by changing one cell
        for i in range(2):
            for j in range(2):
                # There are 4 cells in each 2x2 sub-grid: (i, j), (i, j+1), (i+1, j), (i+1, j+1)
                cells = [(i, j), (i, j+1), (i+1, j), (i+1, j+1)]
                for cx, cy in cells:
                    original = grid[cx][cy]
                    # Change the cell to the other color
                    grid[cx][cy] = 'B' if original == 'W' else 'W'
                    # Check if this change leads to a uniform 2x2 square
                    if is_same_color(i, j):
                        return True
                    # Revert the change
                    grid[cx][cy] = original
        
        return False
