from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        result = []
        if not matrix:
            return result
        
        row_start, row_end = 0, len(matrix)
        col_start, col_end = 0, len(matrix[0])
        
        while row_start < row_end and col_start < col_end:
            # Traverse Right
            for col in range(col_start, col_end):
                result.append(matrix[row_start][col])
            row_start += 1
            
            # Traverse Down
            for row in range(row_start, row_end):
                result.append(matrix[row][col_end - 1])
            col_end -= 1
            
            if row_start < row_end:
                # Traverse Left
                for col in range(col_end - 1, col_start - 1, -1):
                    result.append(matrix[row_end - 1][col])
                row_end -= 1
            
            if col_start < col_end:
                # Traverse Up
                for row in range(row_end - 1, row_start - 1, -1):
                    result.append(matrix[row][col_start])
                col_start += 1
        
        return result
