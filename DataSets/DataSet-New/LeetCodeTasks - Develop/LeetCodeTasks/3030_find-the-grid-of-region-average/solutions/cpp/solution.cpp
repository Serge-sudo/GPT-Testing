#include <vector>
#include <cmath>

class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> result(m, vector<int>(n));
        vector<vector<vector<int>>> regions(m, vector<vector<int>>(n));

        // Helper function to check if a 3x3 region starting at (row, col) is valid
        auto isValidRegion = [&](int row, int col) {
            for (int i = row; i < row + 3; i++) {
                for (int j = col; j < col + 3; j++) {
                    if (i > row && abs(image[i][j] - image[i-1][j]) > threshold)
                        return false;
                    if (j > col && abs(image[i][j] - image[i][j-1]) > threshold)
                        return false;
                }
            }
            return true;
        };

        // Calculate and store the average intensities of valid regions
        for (int i = 0; i <= m - 3; i++) {
            for (int j = 0; j <= n - 3; j++) {
                if (isValidRegion(i, j)) {
                    int sum = 0;
                    for (int x = i; x < i + 3; x++) {
                        for (int y = j; y < j + 3; y++) {
                            sum += image[x][y];
                        }
                    }
                    int avg = sum / 9;
                    for (int x = i; x < i + 3; x++) {
                        for (int y = j; y < j + 3; y++) {
                            regions[x][y].push_back(avg);
                        }
                    }
                }
            }
        }

        // Calculate the final intensities for the result grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (regions[i][j].empty()) {
                    result[i][j] = image[i][j];
                } else {
                    int sum = 0;
                    for (int avg : regions[i][j]) {
                        sum += avg;
                    }
                    result[i][j] = sum / regions[i][j].size();
                }
            }
        }

        return result;
    }
};
