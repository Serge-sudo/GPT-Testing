#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0;
        double longestDiagonal = 0;

        for (const auto& dim : dimensions) {
            int length = dim[0];
            int width = dim[1];
            double diagonal = sqrt(length * length + width * width);
            int area = length * width;
            
            if (diagonal > longestDiagonal) {
                longestDiagonal = diagonal;
                maxArea = area;
            } else if (diagonal == longestDiagonal) {
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }
        
        return maxArea;
    }
};
