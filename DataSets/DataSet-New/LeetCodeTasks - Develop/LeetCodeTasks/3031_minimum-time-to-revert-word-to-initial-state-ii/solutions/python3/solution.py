class Solution:
    def minimumTimeToInitialState(self, word: str, k: int) -> int:
        n = len(word)
        if k == n:
            return 1
        
        # Calculate the cycle length to revert back to the initial position
        cycle_length = n // k
        if n % k == 0:
            return cycle_length
        else:
            return cycle_length + 1
