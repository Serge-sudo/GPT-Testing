#include <string>

class Solution {
public:
    int countKeyChanges(std::string s) {
        int changes = 0; // Initialize changes to 0
        for (int i = 1; i < s.length(); ++i) { // Start loop from index 1
            if (tolower(s[i]) != tolower(s[i - 1])) { // Compare with previous character
                changes++;
            }
        }
        return changes;
    }
};
