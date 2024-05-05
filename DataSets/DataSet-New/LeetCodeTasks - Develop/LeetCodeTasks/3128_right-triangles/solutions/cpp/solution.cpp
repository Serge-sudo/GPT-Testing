#include <vector>
using namespace std;

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> rowCount(rows, 0);
        vector<int> colCount(cols, 0);

        // Count the number of 1s in each row and each column
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        long long totalTriangles = 0;
        // Calculate the possible right triangles for each '1' that can be the right-angle point
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    // Each pair of 1s in the same row and column form a right triangle
                    totalTriangles += (rowCount[i] - 1) * (colCount[j] - 1);
                }
            }
        }

        return totalTriangles;
    }
};
