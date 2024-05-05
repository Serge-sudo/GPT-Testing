import java.util.Arrays;

class Solution {
    private static final int MOD = 1000000007;

    public int numberOfStableArrays(int zero, int one, int limit) {
        // Using dynamic programming where dp[i][j] represents the count of stable arrays with
        // exactly i zeroes and j ones that end in the current state (0 or 1).
        // Specifically, dp0[i][j] - ends in 0, dp1[i][j] - ends in 1
        int[][] dp0 = new int[zero + 1][one + 1];
        int[][] dp1 = new int[zero + 1][one + 1];

        // Base cases
        if (zero > 0) dp0[1][0] = 1; // Single element array ending with 0
        if (one > 0) dp1[0][1] = 1; // Single element array ending with 1

        // Fill the DP tables
        for (int z = 0; z <= zero; z++) {
            for (int o = 0; o <= one; o++) {
                if (z == 0 && o == 0) continue; // Skip the empty case

                if (z > 0) {
                    // Accumulate results for ending with 0, considering a maximum of `limit` previous 1's
                    for (int k = 1; k <= limit && k <= o; k++) {
                        dp0[z][o] = (dp0[z][o] + dp1[z][o - k]) % MOD;
                    }
                }
                
                if (o > 0) {
                    // Accumulate results for ending with 1, considering a maximum of `limit` previous 0's
                    for (int k = 1; k <= limit && k <= z; k++) {
                        dp1[z][o] = (dp1[z][o] + dp0[z - k][o]) % MOD;
                    }
                }
            }
        }

        // Final result is the sum of configurations that end with either 0 or 1 with exact count of zero's and one's
        return (dp0[zero][one] + dp1[zero][one]) % MOD;
    }
}
