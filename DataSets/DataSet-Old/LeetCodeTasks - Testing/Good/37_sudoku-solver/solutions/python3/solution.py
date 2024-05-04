class Solution:
    def solveSudoku(self, board):
        """
        Do not return anything, modify board in-place instead.
        """
        def is_valid_move(x, y, val):
            # Check if the value is already in the row
            for j in range(9):
                if board[x][j] == val:
                    return False
            # Check if the value is already in the column
            for i in range(9):
                if board[i][y] == val:
                    return False
            # Check if the value is already in the 3x3 grid
            startRow = x - x % 3
            startCol = y - y % 3
            for i in range(3):
                for j in range(3):
                    if board[startRow + i][startCol + j] == val:
                        return False
            return True
        
        def solve():
            for i in range(9):
                for j in range(9):
                    if board[i][j] == '.':
                        for num in '123456789':
                            if is_valid_move(i, j, num):
                                board[i][j] = num
                                if solve():
                                    return True
                                board[i][j] = '.'
                        return False
            return True
        
        solve()
