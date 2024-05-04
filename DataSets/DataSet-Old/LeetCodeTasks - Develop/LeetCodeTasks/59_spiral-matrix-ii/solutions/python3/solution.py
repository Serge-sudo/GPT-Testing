from typing import List

class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        matrix = [[0] * n for _ in range(n)]
        row_begin, row_end = 0, n
        col_begin, col_end = 0, n
        current = 1
        
        while row_begin < row_end and col_begin < col_end:
            # Traverse Right
            for col in range(col_begin, col_end):
                matrix[row_begin][col] = current
                current += 1
            row_begin += 1
            
            # Traverse Down
            for row in range(row_begin, row_end):
                matrix[row][col_end - 1] = current
                current += 1
            col_end -= 1
            
            if row_begin < row_end:
                # Traverse Left
                for col in range(col_end - 1, col_begin - 1, -1):
                    matrix[row_end - 1][col] = current
                    current += 1
                row_end -= 1

            if col_begin < col_end:
                # Traverse Up
                for row in range(row_end - 1, row_begin - 1, -1):
                    matrix[row][col_begin] = current
                    current += 1
                col_begin += 1
        
        return matrix
