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

            // Move to the next point outside the current rectangle range
            while (i < n && points[i][0] <= x_end) {
                i++;
            }
        }

        return count;
    }
};
