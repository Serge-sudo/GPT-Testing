class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        MOD = 10**9 + 7
        
        if zero == 0 or one == 0:
            return 1 if zero + one == 1 else 0
        
        # Initialize the dp array
        # dp[i][j][k] means the number of ways to form a valid sequence using i zeros and j ones
        # where k represents the last element of the sequence (0 for zero, 1 for one)
        dp = [[[0 for _ in range(2)] for _ in range(one + 1)] for _ in range(zero + 1)]
        
        # Base cases
        dp[1][0][0] = 1  # Sequence of exactly one 0
        dp[0][1][1] = 1  # Sequence of exactly one 1
        
        for i in range(zero + 1):
            for j in range(one + 1):
                if i + j > 1:  # We start checking once we have at least one element to consider
                    for k in range(2):  # k = 0 or 1
                        if k == 0:  # Ending with 0
                            if i > 0:  # We need at least one zero to place
                                # Add sequences ending in one (j is unchanged, i is decreased)
                                # We cannot add more than limit zeros continuously
                                for l in range(1, min(limit, i) + 1):
                                    dp[i][j][k] += dp[i - l][j][1]
                                    dp[i][j][k] %= MOD
                        else:  # Ending with 1
                            if j > 0:
                                # Add sequences ending in zero (i is unchanged, j is decreased)
                                # We cannot add more than limit ones continuously
                                for l in range(1, min(limit, j) + 1):
                                    dp[i][j][k] += dp[i][j - l][0]
                                    dp[i][j][k] %= MOD
        
        # Return the sum of the number of sequences using all zeros and ones ending in either 0 or 1
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD
