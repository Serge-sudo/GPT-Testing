#include <vector>
#include <cmath>

class Solution {
public:
    int areaOfMaxDiagonal(std::vector<std::vector<int>>& dimensions) {
        int maxDiagonalSq = 0; // Maximum diagonal squared
        int maxArea = 0; // Maximum area corresponding to the maximum diagonal squared

        for (const auto& dim : dimensions) {
            int length = dim[0];
            int width = dim[1];
            int diagonalSq = length * length + width * width; // Calculate diagonal squared
            int area = length * width; // Calculate area

            if (diagonalSq > maxDiagonalSq) {
                maxDiagonalSq = diagonalSq;
                maxArea = area;
            } else if (diagonalSq == maxDiagonalSq) {
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }

        return maxArea;
    }
};
