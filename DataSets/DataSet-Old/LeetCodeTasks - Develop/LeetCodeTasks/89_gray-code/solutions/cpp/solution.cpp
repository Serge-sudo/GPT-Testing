#include <vector>

class Solution {
public:
    std::vector<int> grayCode(int n) {
        std::vector<int> result;
        for (int i = 0; i < (1 << n); ++i) {
            result.push_back(i ^ (i >> 1));
        }
        return result;
    }
};
