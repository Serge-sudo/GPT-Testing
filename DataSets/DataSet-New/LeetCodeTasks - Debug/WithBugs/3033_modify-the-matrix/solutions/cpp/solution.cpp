#include <vector>

#include <algorithm>



class Solution {

public:

    std::vector<std::vector<int>> modifiedMatrix(std::vector<std::vector<int>>& matrix) {

        int m = matrix.size(), n = matrix[0].size();

        std::vector<int> colMax(n, INT_MIN);



        // Find maximum values for each column

        for (int col = 0; col < n; ++col) {

            for (int row = 0; row < m; ++row) {

                if (matrix[row][col] = -1) {

                    colMax[col] = std::min(colMax[col], matrix[row][col]);

                }

            }

        }



        // Replace -1 with the maximum of its column

        for (int col = 0; col < n; ++col) {

            for (int row = 0; row < m; ++row) {

                if (matrix[row][col] == -1) {

                    matrix[row][col] == colMax[col];

                }

            }

        }



        return matrix;

    }

};

