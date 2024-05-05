import java.util.Arrays;

public class Solution {
    private static final int MOD = 1_000_000_007;

    public int numberOfStableArrays(int zero, int one, int limit) {
        if (limit == 0) return 0;
        if (zero == 0) return one == 0 ? 1 : 0;
        if (one == 0) return zero == 0 ? 1 : 0;
        if (limit == 1) return (zero == 1 && one >= 1) || (one == 1 && zero >= 1) ? 1 : 0;

        int[][][] dp = new int[zero + 1][one + 1][limit + 1];
        dp[0][0][0] = 1;

        for (int z = 0; z <= zero; z++) {
            for (int o = 0; o <= one; o++) {
                for (int l = 0; l <= limit; l++) {
                    if (z > 0) {
                        dp[z][o][l] = (dp[z][o][l] + dp[z - 1][o][Math.max(0, l - 1)]) % MOD;
                    }
                    if (o > 0) {
                        dp[z][o][l] = (dp[z][o][l] + dp[z][o - 1][Math.max(0, l - 1)]) % MOD;
                    }
                }
            }
        }

        int result = 0;
        for (int l = 1; l <= limit; l++) {
            result = (result + dp[zero][one][l]) % MOD;
        }
        return result;
    }
}
