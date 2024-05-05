#include <string>

class Solution {
public:
    int countKeyChanges(std::string s) {
        int changes = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (tolower(s[i]) != tolower(s[i - 1])) {
                changes++;
            }
        }
        return changes;
    }
};
