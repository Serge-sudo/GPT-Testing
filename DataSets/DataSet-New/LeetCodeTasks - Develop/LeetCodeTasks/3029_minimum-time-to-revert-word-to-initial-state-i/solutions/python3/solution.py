class Solution:
    def minimumTimeToInitialState(self, word: str, k: int) -> int:
        n = len(word)
        if n == k:
            return 1
        
        # Cycle length calculation using properties of string rotation
        def cycle_length(k, n):
            # The cycle length for any k is when k * steps % n == 0, i.e., when steps is a multiple of n/gcd(n, k)
            from math import gcd
            return n // gcd(n, k)
        
        return cycle_length(k, n)
