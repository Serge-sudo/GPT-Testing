#include <vector>
#include <algorithm>

class Solution {
public:
    int numberOfPairs(std::vector<std::vector<int>>& points) {
        int n = points.size();
        int validPairs = 0;

        // Sort the points based on x, then y coordinate
        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        // Iterate over each possible pair of points
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                bool valid = true;
                // Alice at i and Bob at j, check if this configuration is valid
                if (points[i][0] <= points[j][0] && points[i][1] >= points[j][1]) {
                    // Iterate over all other points to see if any lie on or inside the fence
                    for (int k = 0; k < n; ++k) {
                        if (k != i && k != j) {
                            if (points[k][0] >= points[i][0] && points[k][0] <= points[j][0] &&
                                points[k][1] <= points[i][1] && points[k][1] >= points[j][1]) {
                                valid = false;
                                break;
                            }
                        }
                    }
                    if (valid) {
                        validPairs++;
                    }
                }
            }
        }

        return validPairs;
    }
};
