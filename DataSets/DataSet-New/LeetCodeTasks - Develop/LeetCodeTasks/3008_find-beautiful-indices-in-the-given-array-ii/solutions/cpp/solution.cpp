#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<int> beautifulIndices(std::string s, std::string a, std::string b, int k) {
        int s_len = s.length();
        int a_len = a.length();
        int b_len = b.length();
        std::vector<int> a_indices;
        std::vector<int> b_indices;
        std::vector<int> result;

        // Find all starting indices where substring a is found
        for (int i = 0; i <= s_len - a_len; ++i) {
            if (s.substr(i, a_len) == a) {
                a_indices.push_back(i);
            }
        }

        // Find all starting indices where substring b is found
        for (int i = 0; i <= s_len - b_len; ++i) {
            if (s.substr(i, b_len) == b) {
                b_indices.push_back(i);
            }
        }

        // Check each a index to find if there is a b index within range k
        for (int ai : a_indices) {
            auto lower = std::lower_bound(b_indices.begin(), b_indices.end(), ai - k);
            auto upper = std::upper_bound(b_indices.begin(), b_indices.end(), ai + k);
            if (lower != upper) {
                result.push_back(ai);
            }
        }

        return result;
    }
};
