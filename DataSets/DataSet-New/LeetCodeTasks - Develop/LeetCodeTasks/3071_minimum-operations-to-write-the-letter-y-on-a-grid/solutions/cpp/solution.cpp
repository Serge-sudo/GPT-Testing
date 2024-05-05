#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumOperationsToWriteY(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int center = n / 2;
        std::vector<int> yCount(3, 0), notYCount(3, 0);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j || i + j == n - 1 || (i > center && j == center)) {
                    yCount[grid[i][j]]++;
                } else {
                    notYCount[grid[i][j]]++;
                }
            }
        }
        
        int minYOps = INT_MAX;
        for (int yValue = 0; yValue < 3; ++yValue) {
            for (int notYValue = 0; notYValue < 3; ++notYValue) {
                if (yValue != notYValue) {
                    int yOps = (2 * center + 1 - yCount[yValue]) + (n - center - 1);
                    int notYOps = (n * n - (2 * center + 1) - (n - center - 1)) - notYCount[notYValue];
                    minYOps = std::min(minYOps, yOps + notYOps);
                }
            }
        }
        
        return minYOps;
    }
};
