#include <algorithm>

class Solution {
public:
    long long flowerGame(int n, int m) {
        long long count = 0;
        for (int x = 1; x <= n; ++x) {
            for (int y = 1; y <= m; ++y) {
                if ((x + y) % 2 == 0 && (x - 1 <= y || y - 1 <= x)) {
                    count++;
                }
            }
        }
        return count;
    }
};
