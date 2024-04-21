#include <string.h>

int min(int a, int b, int c) {
    if (a < b && a < c) return a;
    if (b < c) return b;
    return c;
}

int minDistance(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;  // Min operations = insert all characters of word2
            } else if (j == 0) {
                dp[i][j] = i;  // Min operations = remove all characters of word1
            } else if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // Characters match, no new operation needed
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j],    // Delete operation
                                   dp[i][j - 1],    // Insert operation
                                   dp[i - 1][j - 1]);  // Replace operation
            }
        }
    }

    return dp[m][n];
}
