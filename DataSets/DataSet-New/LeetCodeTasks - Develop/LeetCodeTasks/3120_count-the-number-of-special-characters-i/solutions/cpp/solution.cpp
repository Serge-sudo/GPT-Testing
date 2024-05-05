#include <string>
#include <set>

class Solution {
public:
    int numberOfSpecialChars(std::string word) {
        std::set<char> lowercaseChars;
        std::set<char> uppercaseChars;
        std::set<char> specialChars;

        for (char c : word) {
            if (islower(c)) {
                if (uppercaseChars.count(toupper(c)))
                    specialChars.insert(tolower(c));
                lowercaseChars.insert(c);
            } else {
                if (lowercaseChars.count(tolower(c)))
                    specialChars.insert(tolower(c));
                uppercaseChars.insert(c);
            }
        }

        return specialChars.size();
    }
};
