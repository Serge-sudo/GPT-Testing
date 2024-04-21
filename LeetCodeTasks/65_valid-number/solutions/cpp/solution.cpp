#include <string>
#include <cctype>

class Solution {
public:
    bool isNumber(std::string s) {
        int n = s.size();
        int i = 0;

        // Function to skip the spaces
        auto skipSpaces = [&]() {
            while (i < n && s[i] == ' ') i++;
        };

        // Check if the part is a valid integer
        auto checkInteger = [&](bool allowSign = true) {
            int start = i;
            if (allowSign && i < n && (s[i] == '+' || s[i] == '-')) i++;
            while (i < n && std::isdigit(s[i])) i++;
            return i > start + (allowSign ? 1 : 0); // At least one digit after sign if present
        };

        // Check if the part is a valid decimal
        auto checkDecimal = [&](bool allowSign = true) {
            int start = i;
            if (allowSign && i < n && (s[i] == '+' || s[i] == '-')) i++;
            bool digitBeforeDot = false, digitAfterDot = false;
            while (i < n && std::isdigit(s[i])) {
                digitBeforeDot = true;
                i++;
            }
            if (i < n && s[i] == '.') {
                i++;
                while (i < n && std::isdigit(s[i])) {
                    digitAfterDot = true;
                    i++;
                }
            }
            return (digitBeforeDot || digitAfterDot) && (digitBeforeDot || !digitAfterDot || i < n);
        };

        skipSpaces();

        // Check for a decimal or integer part
        bool isValidNumber = checkDecimal();

        // Check for an exponential part
        if (i < n && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            isValidNumber = isValidNumber && checkInteger();
        }

        skipSpaces();

        return isValidNumber && i == n;
    }
};
