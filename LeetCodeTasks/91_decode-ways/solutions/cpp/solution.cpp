#include <string>
#include <vector>

class Solution {
public:
    int numDecodings(std::string s) {
        int n = s.size();
        if (s[0] == '0') return 0;  // If the string starts with '0', it's not decodable.

        // dp[i] will store the number of ways to decode the string of length i.
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1;  // Base case: There's one way to decode an empty string.
        dp[1] = 1;  // Base case: There's one way to decode a non-'0' single character.

        for (int i = 2; i <= n; ++i) {
            int oneDigit = s[i - 1] - '0';  // One digit number ending at i-1
            int twoDigits = (s[i - 2] - '0') * 10 + oneDigit;  // Two digit number ending at i-1

            if (oneDigit > 0) {
                dp[i] += dp[i - 1];  // If the last digit is not '0', it can be used as a letter.
            }
            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[i] += dp[i - 2];  // If the last two digits form a valid number from 10 to 26.
            }
        }

        return dp[n];
    }
};
