from typing import List

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def is_valid(row, col):
            for prev_row in range(row):
                prev_col = board[prev_row]
                if prev_col == col or abs(prev_col - col) == row - prev_row:
                    return False
            return True
        
        def place_queen(row):
            if row == n:
                result.append(['.' * c + 'Q' + '.' * (n - c - 1) for c in board])
                return
            
            for col in range(n):
                if is_valid(row, col):
                    board[row] = col
                    place_queen(row + 1)
                    board[row] = -1
        
        result = []
        board = [-1] * n
        place_queen(0)
        return result
