#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        int n = s.length();
        while (index < n && s[index] == ' ') {
            ++index;
        }

        int sign = 1;
        if (index < n && (s[index] == '+' || s[index] == '-')) {
            sign = (s[index] == '-') ? -1 : 1;
            ++index;
        }

        long long result = 0;
        while (index < n && isdigit(s[index])) {
            result = result * 10 + (s[index] - '0');
            if (sign == 1 && result > INT_MAX) {
                return INT_MAX;
            } else if (sign == -1 && -result < INT_MIN) {
                return INT_MIN;
            }
            ++index;
        }

        return static_cast<int>(result * sign);
    }
};
