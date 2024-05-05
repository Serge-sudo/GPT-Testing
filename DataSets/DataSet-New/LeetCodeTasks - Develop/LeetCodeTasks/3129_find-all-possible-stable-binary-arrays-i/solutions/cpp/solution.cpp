#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1000000007;
        vector<vector<vector<int>>> dp(zero + 1, vector<vector<int>>(one + 1, vector<int>(limit + 1, 0)));
        
        // Base cases
        if (zero > 0) dp[1][0][1] = 1; // Array with a single 0
        if (one > 0) dp[0][1][1] = 1;  // Array with a single 1
        
        for (int z = 0; z <= zero; ++z) {
            for (int o = 0; o <= one; ++o) {
                for (int l = 1; l <= limit; ++l) {
                    if (z == 0 && o == 0) continue; // Skip the zero length array case
                    if (z + o == 1) continue;       // Skip already initialized base cases
                    
                    // If we can place another 0
                    if (z > 0) {
                        dp[z][o][l] = (dp[z][o][l] + (l > 1 ? dp[z - 1][o][l - 1] : dp[z - 1][o][min(o, limit)])) % MOD;
                    }
                    
                    // If we can place another 1
                    if (o > 0) {
                        dp[z][o][l] = (dp[z][o][l] + (l > 1 ? dp[z][o - 1][l - 1] : dp[z][o - 1][min(z, limit)])) % MOD;
                    }
                }
            }
        }
        
        int result = 0;
        for (int l = 1; l <= limit; ++l) {
            result = (result + dp[zero][one][l]) % MOD;
        }
        
        return result;
    }
};
