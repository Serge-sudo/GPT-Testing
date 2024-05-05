#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int count = 0;
        int n = points.size();

        // Map to track count of points at each coordinate
        unordered_map<int, unordered_map<int, int>> pointMap;
        for (const auto& p : points) {
            pointMap[p[0]][p[1]] = 1;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;

                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                // Alice at (x1, y1) and Bob at (x2, y2)
                // Alice's position must be upper left; hence, x1 < x2 and y1 > y2
                if (x1 < x2 && y1 > y2) {
                    bool isValid = true;

                    // Check if any other point lies in the rectangle or on its boundaries
                    for (int k = 0; k < n; ++k) {
                        if (k != i && k != j) {
                            int x = points[k][0], y = points[k][1];
                            if (x1 <= x && x <= x2 && y2 <= y && y <= y1) {
                                isValid = false;
                                break;
                            }
                        }
                    }

                    if (isValid) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
