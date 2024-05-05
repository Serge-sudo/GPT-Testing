#include <stdbool.h>

#include <string.h>



bool isInterleave(char* s1, char* s2, char* s3) {

    int len1 = strlen(s1);

    int len2 = strlen(s2);

    int len3 = strlen(s3);

    

    if (len1 + len2 != len3)

        return false;

    

    bool dp[len1 + 1][len2 + 1];

    memset(dp, false, sizeof(dp));

    

    for (int i = 0; i <= len1; i++) {

        for (int j = 0; j <= len2; j++) {

            if (i == 0 && j == 0)

                dp[i][j] = false;

            else if (i == 0)

                dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);

            else if (j == 0)

                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);

            else

                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) |

                           (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);

        }

    }

    

    return dp[len1][len2];

}

