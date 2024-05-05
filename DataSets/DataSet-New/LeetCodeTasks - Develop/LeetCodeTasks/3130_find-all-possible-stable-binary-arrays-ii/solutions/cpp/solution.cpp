#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1'000'000'007;

        if (limit >= zero + one) {
            // If limit is greater than or equal to total number of elements,
            // no subarray can violate the condition of having both 0 and 1.
            // The task is then simply to count the number of permutations of `zero` zeros and `one` ones.
            return countPermutations(zero, one, MOD);
        }

        // Initialize dp array
        vector<vector<vector<int>>> dp(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, 0)));
        // Base case for an empty array
        dp[0][0][0] = dp[0][0][1] = 1;

        // Fill the dp table
        for (int z = 0; z <= zero; ++z) {
            for (int o = 0; o <= one; ++o) {
                for (int i = 0; i <= 1; ++i) { // Current ending element: 0 or 1
                    if (i == 0 && z == 0) continue; // No more zeros to place
                    if (i == 1 && o == 0) continue; // No more ones to place

                    int &current = dp[z][o][i];
                    // Add zeros
                    if (i == 0) {
                        for (int use = 1; use <= min(limit, z); ++use) {
                            current = (current + dp[z - use][o][1 - i]) % MOD;
                        }
                    }
                    // Add ones
                    if (i == 1) {
                        for (int use = 1; use <= min(limit, o); ++use) {
                            current = (current + dp[z][o - use][1 - i]) % MOD;
                        }
                    }
                }
            }
        }

        // The result is the sum of configurations ending in zero and one
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }

    int countPermutations(int zero, int one, int MOD) {
        vector<int> factorial(zero + one + 1);
        factorial[0] = 1;
        for (int i = 1; i <= zero + one; ++i) {
            factorial[i] = (int)((long long)factorial[i - 1] * i % MOD);
        }
        long long result = factorial[zero + one];
        result = result * modInverse(factorial[zero], MOD) % MOD;
        result = result * modInverse(factorial[one], MOD) % MOD;
        return result;
    }

    int modInverse(int a, int MOD) {
        int m0 = MOD, t, q;
        int x0 = 0, x1 = 1;
        if (MOD == 1) return 0;

        // Apply extended Euclid Algorithm
        while (a > 1) {
            // q is quotient
            q = a / MOD;
            t = MOD;

            // MOD is remainder now, process same as
            // Euclid's algo
            MOD = a % MOD, a = t;
            t = x0;

            x0 = x1 - q * x0;
            x1 = t;
        }

        // Make x1 positive
        if (x1 < 0) x1 += m0;

        return x1;
    }
};
