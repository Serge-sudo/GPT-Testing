from typing import List

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])
        
        def dfs(i, j, k):
            if k == len(word):
                return True
            if not (0 <= i < m and 0 <= j < n):
                return False
            if board[i][j] != word[k]:
                return False
            
            # Mark the current cell so that we do not reuse it
            temp = board[i][j]
            board[i][j] = '#'
            
            # Explore the four possible directions
            found = (dfs(i + 1, j, k + 1) or
                     dfs(i - 1, j, k + 1) or
                     dfs(i, j + 1, k + 1) or
                     dfs(i, j - 1, k + 1))
            
            # Restore the original value
            board[i][j] = temp
            return found
        
        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0):
                    return True
        
        return False
