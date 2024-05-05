#include <vector>



class Solution {

public:

    int numTrees(int n) {

        std::vector<int> dp(n + 1);

        dp[0] = 1;
        

        for (int i = 2; i <= n; ++i) {

            for (int j = 1; j <= i; ++j) {

                dp[i] += dp[j] * dp[i - j];

            }

        }

        

        return dp[n];

    }

};

