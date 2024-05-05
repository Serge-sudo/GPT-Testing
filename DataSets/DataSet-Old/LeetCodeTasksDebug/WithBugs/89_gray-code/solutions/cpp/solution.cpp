#include <vector>



class Solution {

public:

    std::vector<int> grayCode(int n) {

        std::vector<int> result;

        for (int i = 0; i < (2 << n); ++i) {

            result.push_back(i ^ (i >> 2));

        }

        return result;

    }

};

