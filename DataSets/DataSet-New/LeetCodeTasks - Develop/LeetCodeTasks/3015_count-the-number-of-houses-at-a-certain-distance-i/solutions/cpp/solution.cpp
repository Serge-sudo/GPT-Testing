#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> countOfPairs(int n, int x, int y) {
        std::vector<int> result(n, 0);
        // Normalizing x and y to ensure x is less than y
        if (x > y) std::swap(x, y);
        
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                // Direct distance without shortcut
                int direct_distance = j - i;
                // Using the shortcut if it's beneficial
                int shortcut_distance = abs(x - i) + 1 + abs(y - j);
                // Take the minimum of both distances
                int min_distance = std::min(direct_distance, shortcut_distance);
                // Count the number of times each distance occurs (for both (i, j) and (j, i))
                if (min_distance < n) {
                    result[min_distance]++;
                }
            }
        }
        
        // Each distance is counted twice: once for (i, j) and once for (j, i)
        for (int k = 1; k < n; ++k) {
            result[k] *= 2;
        }
        
        return result;
    }
};
