#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> result(n, 0);
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (abs(i - j) + 1 == k || (abs(i - x) + abs(j - y) + 1) == k) {
                        ++result[k - 1];
                    }
                }
            }
        }
        return result;
    }
};
