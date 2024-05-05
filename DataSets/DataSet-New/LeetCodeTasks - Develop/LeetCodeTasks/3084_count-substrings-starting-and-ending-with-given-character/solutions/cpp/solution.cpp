#include <vector>
#include <string>

class Solution {
public:
    long long countSubstrings(std::string s, char c) {
        std::vector<int> positions;
        long long count = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == c) {
                positions.push_back(i);
            }
        }

        for (int index : positions) {
            count += (index + 1) * (s.length() - index);
        }

        return count;
    }
};
