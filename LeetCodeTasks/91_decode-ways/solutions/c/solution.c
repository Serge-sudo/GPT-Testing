#include <stdio.h>
#include <string.h>

int numDecodings(char* s) {
    int n = strlen(s);
    if (n == 0 || s[0] == '0') return 0;
    if (n == 1) return 1;

    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (s[i-1] != '0')
            dp[i] = dp[i-1];
        else
            dp[i] = 0;
        
        int twoDigits = (s[i-2] - '0') * 10 + (s[i-1] - '0');
        if (twoDigits >= 10 && twoDigits <= 26)
            dp[i] += dp[i-2];
    }

    return dp[n];
}
