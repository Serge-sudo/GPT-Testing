#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::string lastNonEmptyString(std::string s) {
        while (true) {
            std::unordered_set<char> seen;
            std::string next_s;

            for (char c : s) {
                if (seen.find(c) == seen.end() && c >= 'a' && c <= 'z') {
                    seen.insert(c);
                } else {
                    next_s.push_back(c);
                }
            }

            if (next_s.empty()) {
                return s;
            }
            s = next_s;
        }
    }
};
