#include <vector>
#include <cmath>

class Solution {
public:
    int minimumOperations(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int operations = 0;

        // Check vertical consistency
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m - 1; ++i) {
                if (grid[i][j] != grid[i + 1][j]) {
                    operations += 1;
                    grid[i + 1][j] = grid[i][j]; // We simulate the change
                }
            }
        }

        // Check horizontal consistency
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                if (grid[i][j] == grid[i][j + 1]) {
                    operations += 1;
                    grid[i][j + 1] = (grid[i][j] + 1) % 10; // Change to a different number
                    if (grid[i][j] == 9) {
                        grid[i][j + 1] = 0; // Handle wrap-around if it's 9 to 0
                    }
                }
            }
        }

        return operations;
    }
};
