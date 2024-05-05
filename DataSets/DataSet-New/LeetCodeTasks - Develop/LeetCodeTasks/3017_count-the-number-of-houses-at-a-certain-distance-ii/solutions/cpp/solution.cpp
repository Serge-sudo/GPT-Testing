#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    std::vector<long long> countOfPairs(int n, int x, int y) {
        // Ensure x is less than or equal to y
        if (x > y) std::swap(x, y);

        std::vector<long long> result(n, 0);
        int shortcut_distance = y - x; // Distance of the shortcut

        // Count pairs for each distance k
        for (int k = 1; k <= n; ++k) {
            long long count = 0;

            // Count linear chain connections within bounds
            if (k < n) {
                count += 2 * (n - k);
            }

            // Count shortcut effect
            if (k == shortcut_distance) {
                count += 2; // (x, y) and (y, x)
            }

            // Subtract shortcut overcounts
            if (k < shortcut_distance) {
                int reduced_by_shortcut = shortcut_distance - k;
                if (x > reduced_by_shortcut) {
                    count -= 2;
                }
                if (n - y + 1 > reduced_by_shortcut) {
                    count -= 2;
                }
            }

            result[k - 1] = count;
        }
        
        return result;
    }
};
