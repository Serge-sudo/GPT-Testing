#include <vector>
#include <algorithm>

class Solution {
public:
    int minRectanglesToCoverPoints(std::vector<std::vector<int>>& points, int w) {
        // Sort points based on the x-coordinate
        std::sort(points.begin(), points.end());
        
        int count = 0;
        int n = points.size();
        int i = 0;
        
        while (i < n) {
            count++;
            int x_start = points[i][0];
            int x_end = x_start + w;
            
            // Find the farthest y-coordinate we need to cover within the current x range [x_start, x_end]
            int max_y = 0;
            while (i < n && points[i][0] <= x_end) {
                max_y = std::max(max_y, points[i][1]);
                i++;
            }
        }
        
        return count;
    }
};
