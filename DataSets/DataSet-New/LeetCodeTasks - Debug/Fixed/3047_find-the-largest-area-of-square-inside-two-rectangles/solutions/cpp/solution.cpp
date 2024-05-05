#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long maxSquareArea = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // Calculate the intersection of rectangle i and rectangle j
                int intersectLeft = max(bottomLeft[i][0], bottomLeft[j][0]);
                int intersectRight = min(topRight[i][0], topRight[j][0]);
                int intersectBottom = max(bottomLeft[i][1], bottomLeft[j][1]);
                int intersectTop = min(topRight[i][1], topRight[j][1]);

                // Check if the intersection forms a valid rectangle
                if (intersectLeft < intersectRight && intersectBottom < intersectTop) {
                    // Calculate the possible side length of the square
                    int sideLength = min(intersectRight - intersectLeft, intersectTop - intersectBottom);
                    maxSquareArea = max(maxSquareArea, (long long)sideLength * sideLength);
                }
            }
        }

        return maxSquareArea;
    }
};
