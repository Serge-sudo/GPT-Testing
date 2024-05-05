#include <stdio.h>
#include <string.h>

#define MOD 1000000007

int numberOfStableArrays(int zero, int one, int limit) {
    if (limit == 0) return 0; // Impossible case for our constraints
    if (limit >= zero + one) return zero == 0 || one == 0 ? 0 : 1; // If the limit is greater than total elements

    long long dp[1001][1001] = {0};
    dp[0][0] = 1; // Base case

    for (int i = 0; i <= zero; ++i) {
        for (int j = 0; j <= one; ++j) {
            if (i == 0 && j == 0) continue; // Skip the base case
            long long countZeros = 0, countOnes = 0;
            
            if (i > 0) {
                countZeros = dp[i-1][j];
                if (j > limit) countZeros = (countZeros - dp[i-1][j-limit-1] + MOD) % MOD;
            }
            
            if (j > 0) {
                countOnes = dp[i][j-1];
                if (i > limit) countOnes = (countOnes - dp[i-limit-1][j-1] + MOD) % MOD;
            }
            
            dp[i][j] = (countZeros + countOnes) % MOD;
        }
    }
    
    return (int)dp[zero][one];
}

// Test cases
int main() {
    printf("%d\n", numberOfStableArrays(1, 1, 2)); // Expected output: 2
    printf("%d\n", numberOfStableArrays(1, 2, 1)); // Expected output: 1
    printf("%d\n", numberOfStableArrays(3, 3, 2)); // Expected output: 14
    return 0;
}
