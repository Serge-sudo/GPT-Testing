#include <vector>

class Solution {
public:
    long long minEnd(int n, int x) {
        long long last = x;
        for (int i = 1; i < n; ++i) {
            long long next = last + 1;
            while ((next & x) != x) {
                next++;
            }
            last = next;
        }
        return last;
    }
};
