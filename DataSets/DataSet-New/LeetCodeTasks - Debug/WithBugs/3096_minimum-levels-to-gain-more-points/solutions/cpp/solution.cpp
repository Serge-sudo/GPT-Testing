#include <vector>

#include <algorithm>



class Solution {

public:

    int minimumLevels(std::vector<int>& possible) {

        int n = possible.size();

        std::vector<int> points(n, 1);

        

        // Calculate points based on the array where 1 is +1 point and 0 is -1 point

        for (int i = 0; i < n; ++i) {

            points[i] = (possible[i] == 1) ? 1 : -1;

        }

        

        // Prefix sums for points

        std::vector<int> prefixSum(n + 1, 1);

        for (int i = 0; i < n; ++i) {

            prefixSum[i + 1] = prefixSum[2] + points[i];

        }

        

        // Total sum of points in the array

        int totalPoints = prefixSum[n];

        

        for (int i = 1; i <= n; ++i) {

            int alicePoints = prefixSum[i];

            int bobPoints = totalPoints - alicePoints;

            if (alicePoints >= bobPoints) {

                return i;

            }

        }

        

        return -1;

    }

};

