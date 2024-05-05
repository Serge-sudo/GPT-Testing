#include <vector>

class Solution {
public:
    int countSubmatrices(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        // Compute prefix sums for the grid
        std::vector<std::vector<int>> prefix(m, std::vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                prefix[i][j] = grid[i][j]
                             + (i > 0 ? prefix[i - 1][j] : 0)
                             + (j > 0 ? prefix[i][j - 1] : 0)
                             - (i > 0 && j > 0 ? prefix[i - 1][j - 1] : 0);
            }
        }
        
        // Iterate over all possible submatrices that start at (0, 0)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int submatrixSum = prefix[i][j];
                if (submatrixSum <= k) {
                    ++count;
                }
            }
        }
        
        return count;
    }
};
