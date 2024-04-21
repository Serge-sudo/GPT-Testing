#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty()) return {};
        
        std::vector<int> spiral;
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        
        while (top <= bottom && left <= right) {
            // Traverse from left to right on the current top
            for (int i = left; i <= right; ++i) {
                spiral.push_back(matrix[top][i]);
            }
            top++;
            
            // Traverse from top to bottom on the current right
            for (int i = top; i <= bottom; ++i) {
                spiral.push_back(matrix[i][right]);
            }
            right--;
            
            if (top <= bottom) {
                // Traverse from right to left on the current bottom
                for (int i = right; i >= left; --i) {
                    spiral.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            if (left <= right) {
                // Traverse from bottom to top on the current left
                for (int i = bottom; i >= top; --i) {
                    spiral.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        
        return spiral;
    }
};
