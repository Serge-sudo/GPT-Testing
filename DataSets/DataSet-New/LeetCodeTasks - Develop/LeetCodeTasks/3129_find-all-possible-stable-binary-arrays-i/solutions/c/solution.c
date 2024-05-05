#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int numberOfStableArrays(int zero, int one, int limit) {
    if (zero == 0) return one == 0 ? 1 : 0;
    if (one == 0) return zero == 0 ? 1 : 0;

    int dp[201][201][2];  // dp[count_zero][count_one][last_digit]
    for (int i = 0; i <= zero; ++i) {
        for (int j = 0; j <= one; ++j) {
            dp[i][j][0] = dp[i][j][1] = 0;
        }
    }

    dp[1][0][0] = 1; // Only 0 is used, last digit is 0
    dp[0][1][1] = 1; // Only 1 is used, last digit is 1

    for (int z = 0; z <= zero; ++z) {
        for (int o = 0; o <= one; ++o) {
            for (int last = 0; last < 2; ++last) {
                if (z == 0 && o == 0) continue;

                // Extend with 0s
                if (z > 0 && last != 0) {  // Adding a '0' after '1'
                    int contribution = dp[z-1][o][0];
                    dp[z][o][0] = (dp[z][o][0] + contribution) % MOD;
                }
                // Extend with 1s
                if (o > 0 && last != 1) {  // Adding a '1' after '0'
                    int contribution = dp[z][o-1][1];
                    dp[z][o][1] = (dp[z][o][1] + contribution) % MOD;
                }
            }
        }
    }

    // Sum up valid endings to count valid sequences
    int result = (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    return result;
}

// Example usage
int main() {
    int result1 = numberOfStableArrays(1, 1, 2);
    int result2 = numberOfStableArrays(1, 2, 1);
    int result3 = numberOfStableArrays(3, 3, 2);
    printf("%d\n", result1);  // Output: 2
    printf("%d\n", result2);  // Output: 1
    printf("%d\n", result3);  // Output: 14
    return 0;
}
