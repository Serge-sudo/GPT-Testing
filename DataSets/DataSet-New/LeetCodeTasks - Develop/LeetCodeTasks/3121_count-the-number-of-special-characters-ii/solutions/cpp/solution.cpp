#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> firstLower;
        unordered_map<char, int> firstUpper;
        
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            if (islower(c)) {
                if (firstLower.find(c) == firstLower.end()) {
                    firstLower[c] = i;
                }
            } else if (isupper(c)) {
                if (firstUpper.find(c) == firstUpper.end()) {
                    firstUpper[c] = i;
                }
            }
        }
        
        int specialCount = 0;
        for (const auto& [c, pos] : firstLower) {
            auto upperCaseIt = firstUpper.find(toupper(c));
            if (upperCaseIt != firstUpper.end() && pos < upperCaseIt->second) {
                specialCount++;
            }
        }
        
        return specialCount;
    }
};
