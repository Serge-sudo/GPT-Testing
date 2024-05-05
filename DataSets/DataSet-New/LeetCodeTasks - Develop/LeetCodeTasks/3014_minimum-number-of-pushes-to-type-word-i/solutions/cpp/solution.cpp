#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumPushes(std::string word) {
        std::sort(word.begin(), word.end());
        int pushes = 0;
        for (int i = 0; i < word.length(); ++i) {
            pushes += (i % 9) + 1;  // Calculate pushes for each character mapped optimally
        }
        return pushes;
    }
};
