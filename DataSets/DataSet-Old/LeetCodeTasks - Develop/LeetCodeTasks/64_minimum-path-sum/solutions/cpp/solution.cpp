#include <vector>
#include <algorithm>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Using DP to solve the problem
        std::vector<std::vector<int>> dp(m, std::vector<int>(n));

        // Initialize the starting point
        dp[0][0] = grid[0][0];

        // Initialize the first column
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        // Initialize the first row
        for (int j = 1; j < n; ++j) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        // Fill the rest of the dp table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        // The right bottom cell has the result of minimum path sum
        return dp[m-1][n-1];
    }
};
