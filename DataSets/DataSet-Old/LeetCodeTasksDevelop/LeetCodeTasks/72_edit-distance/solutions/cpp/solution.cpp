#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; i++) {
            dp[i][0] = i; // deleting all characters from word1 to match an empty word2
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j; // inserting all characters to match word2 from an empty word1
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // characters match, no operation needed
                } else {
                    dp[i][j] = 1 + min({dp[i - 1][j], // delete
                                        dp[i][j - 1], // insert
                                        dp[i - 1][j - 1]}); // replace
                }
            }
        }
        return dp[m][n];
    }
};
