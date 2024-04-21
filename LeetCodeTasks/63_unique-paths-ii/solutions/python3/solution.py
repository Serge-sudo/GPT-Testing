from typing import List

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        # If the starting or ending point is an obstacle, return 0 paths.
        if obstacleGrid[0][0] == 1 or obstacleGrid[m-1][n-1] == 1:
            return 0
        
        # Initialize the dynamic programming grid with zeros.
        dp = [[0] * n for _ in range(m)]
        # Starting point has 1 way if not an obstacle.
        dp[0][0] = 1
        
        # Fill the dp grid
        for i in range(m):
            for j in range(n):
                if obstacleGrid[i][j] == 1:
                    dp[i][j] = 0
                else:
                    if i > 0:
                        dp[i][j] += dp[i-1][j]
                    if j > 0:
                        dp[i][j] += dp[i][j-1]
                        
        return dp[m-1][n-1]
