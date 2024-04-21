#include <vector>

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int value = 1;
        int rowStart = 0, rowEnd = n - 1;
        int colStart = 0, colEnd = n - 1;
        
        while (rowStart <= rowEnd && colStart <= colEnd) {
            // Traverse Right
            for (int col = colStart; col <= colEnd; col++) {
                matrix[rowStart][col] = value++;
            }
            rowStart++;
            
            // Traverse Down
            for (int row = rowStart; row <= rowEnd; row++) {
                matrix[row][colEnd] = value++;
            }
            colEnd--;
            
            // Traverse Left
            if (rowStart <= rowEnd) {
                for (int col = colEnd; col >= colStart; col--) {
                    matrix[rowEnd][col] = value++;
                }
            }
            rowEnd--;
            
            // Traverse Up
            if (colStart <= colEnd) {
                for (int row = rowEnd; row >= rowStart; row--) {
                    matrix[row][colStart] = value++;
                }
            }
            colStart++;
        }
        
        return matrix;
    }
};
