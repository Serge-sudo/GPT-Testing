class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        from functools import lru_cache
        
        MOD = 1000000007

        # Early exit condition
        if min(zero, one) == 0:  # If either zero or one is zero
            return 1 if max(zero, one) <= limit else 0
        
        @lru_cache(None)
        def dp(z, o, last, consecutive):
            # Base case: no zeros or ones left to place
            if z == 0 and o == 0:
                return 1
            ways = 0
            # Can place a zero if there are zeros left and we're not violating the limit
            if z > 0 and (last != 0 or consecutive < limit):
                ways += dp(z - 1, o, 0, consecutive + 1 if last == 0 else 1)
                ways %= MOD
            # Can place a one if there are ones left and we're not violating the limit
            if o > 0 and (last != 1 or consecutive < limit):
                ways += dp(z, o - 1, 1, consecutive + 1 if last == 1 else 1)
                ways %= MOD
            return ways

        # Start with placing a 0 or a 1
        return (dp(zero - 1, one, 0, 1) + dp(zero, one - 1, 1, 1)) % MOD
