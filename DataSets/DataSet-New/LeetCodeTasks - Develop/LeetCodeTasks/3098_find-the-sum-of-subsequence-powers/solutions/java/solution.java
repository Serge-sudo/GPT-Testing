import java.util.Arrays;

public class Solution {
    private static final int MOD = 1000000007;

    public int sumOfPowers(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        long result = 0;

        // Precompute factorials and their modular inverses for combinations
        long[] fact = new long[n + 1];
        long[] ifact = new long[n + 1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        ifact[n] = modInverse(fact[n], MOD);
        for (int i = n - 1; i >= 0; i--) {
            ifact[i] = ifact[i + 1] * (i + 1) % MOD;
        }

        // Calculate combination function
        long[][] choose = new long[n + 1][k + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= Math.min(i, k); j++) {
                if (j == 0) choose[i][j] = 1;
                else choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1]) % MOD;
            }
        }

        // Sum powers over all relevant subsequences
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long power = Math.abs(nums[j] - nums[i]);
                long countLeft = choose[i][k - 2]; // Choose (k-2) elements from left side of i
                long countRight = choose[n - j - 1][k - 2]; // Choose (k-2) elements from right side of j
                result = (result + power * countLeft % MOD * countRight % MOD) % MOD;
            }
        }

        return (int) result;
    }

    private long modInverse(long a, long m) {
        long m0 = m, t, q;
        long x0 = 0, x1 = 1;
        if (m == 1)
            return 0;
        while (a > 1) {
            // q is quotient
            q = a / m;
            t = m;
            // m is remainder now, process same as Euclid's algo
            m = a % m;
            a = t;
            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }
        // Make x1 positive
        if (x1 < 0)
            x1 += m0;
        return x1;
    }
}
