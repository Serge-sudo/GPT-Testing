#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        int n = points.size();

        // Creating vectors to hold the values of x + y and x - y
        vector<int> plus(n), minus(n);
        for (int i = 0; i < n; ++i) {
            plus[i] = points[i][0] + points[i][1];
            minus[i] = points[i][0] - points[i][1];
        }

        // Calculating the maximum and minimum values for x + y and x - y
        int maxPlus = *max_element(plus.begin(), plus.end());
        int minPlus = *min_element(plus.begin(), plus.end());
        int maxMinus = *max_element(minus.begin(), minus.end());
        int minMinus = *min_element(minus.begin(), minus.end());

        int result = INT_MAX;

        // For each point we remove, calculate the maximum Manhattan distance
        for (int i = 0; i < n; ++i) {
            int newMaxPlus = INT_MIN, newMinPlus = INT_MAX;
            int newMaxMinus = INT_MIN, newMinMinus = INT_MAX;

            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    newMaxPlus = max(newMaxPlus, plus[j]);
                    newMinPlus = min(newMinPlus, plus[j]);
                    newMaxMinus = max(newMaxMinus, minus[j]);
                    newMinMinus = min(newMinMinus, minus[j]);
                }
            }

            // Update result for the removed point
            int localMax = max(newMaxPlus - newMinPlus, newMaxMinus - newMinMinus);
            result = min(result, localMax);
        }

        return result;
    }
};
