from typing import List

class Solution:
    def minimumOperationsToWriteY(self, grid: List[List[int]]) -> int:
        n = len(grid)
        mid = n // 2
        
        # Collect all Y positions
        y_positions = set()
        # Main diagonal and secondary diagonal
        for i in range(mid + 1):
            y_positions.add((i, i))
            y_positions.add((i, n - 1 - i))
        # Vertical line
        for i in range(mid, n):
            y_positions.add((i, mid))
        
        # Collect all non-Y positions
        non_y_positions = set()
        for r in range(n):
            for c in range(n):
                if (r, c) not in y_positions:
                    non_y_positions.add((r, c))
        
        # Count frequencies of values in Y and non-Y cells
        y_count = [0, 0, 0]  # Count of 0, 1, 2 in Y region
        non_y_count = [0, 0, 0]  # Count of 0, 1, 2 in non-Y region
        
        for r in range(n):
            for c in range(n):
                if (r, c) in y_positions:
                    y_count[grid[r][c]] += 1
                else:
                    non_y_count[grid[r][c]] += 1
        
        # Compute minimal operations required to make all Y one value and non-Y another value
        min_operations = float('inf')
        for y_val in range(3):
            for non_y_val in range(3):
                if y_val != non_y_val:
                    # Operations to make all Y cells y_val
                    y_ops = sum(y_count) - y_count[y_val]
                    # Operations to make all non-Y cells non_y_val
                    non_y_ops = sum(non_y_count) - non_y_count[non_y_val]
                    # Total operations
                    min_operations = min(min_operations, y_ops + non_y_ops)
        
        return min_operations
