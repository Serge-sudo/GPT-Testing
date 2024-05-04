#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> countOfPairs(int n, int x, int y) {
        vector<long long> result(n, 0);
        int dist_x_y = abs(x - y);
        for (int k = 1; k <= n; ++k) {
            if (k <= dist_x_y) {
                result[k]++;
            }
            for (int d = 1; d <= n - k; ++d) {
                if (k + d > dist_x_y) {
                    result[k]++;
                }
            }
        }
        return result;
    }
};
