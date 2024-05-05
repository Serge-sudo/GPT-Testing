#include <stdbool.h>
#include <string.h>

bool isMatch(char* s, char* p) {
    int sLen = strlen(s);
    int pLen = strlen(p);
    int dp[sLen+1][pLen+1];

    // Initialize the DP table
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;  // Both strings are empty

    // When s is empty, we need to check if p can match an empty string
    for (int j = 1; j <= pLen; j++) {
        if (p[j-1] == '*')
            dp[0][j] = dp[0][j-1];
    }

    // Fill the DP table
    for (int i = 1; i <= sLen; i++) {
        for (int j = 1; j <= pLen; j++) {
            if (p[j-1] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            } else if (p[j-1] == '?' || s[i-1] == p[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }

    return dp[sLen][pLen];
}
