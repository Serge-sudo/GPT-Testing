class Solution:
    def minimumPushes(self, word: str) -> int:
        # Number of keys available for mapping
        num_keys = 8  # from 2 to 9 inclusive

        # The cost for each character is minimized by assigning it to the first positions on each key
        # where the number of pushes is minimized.
        
        # The optimal way is to sort letters by frequency (descending) and assign them to keys
        # such that the most frequent get the fewest pushes. However, each letter is distinct
        # and used exactly once in our problem.
        
        # Calculate the minimal number of pushes by evenly distributing the letters across the keys.
        # If `n` is the number of letters, and `num_keys` is the number of keys,
        # then the ideal situation is to distribute the letters as evenly as possible across the keys.
        
        # General approach:
        # - Sort the characters in descending order of frequency.
        # - Allocate characters to keys, trying to balance the number of pushes.
        
        n = len(word)  # Number of distinct letters in the word
        
        # Each key can handle at least n // num_keys letters
        min_pushes_per_key = n // num_keys
        extra_letters = n % num_keys
        
        # Cost calculation:
        # Letters assigned to the first `extra_letters` keys will have `min_pushes_per_key + 1` letters each.
        # Remaining keys will have `min_pushes_per_key` letters each.
        
        # Calculate the total pushes:
        total_pushes = 0
        
        # For keys with an extra letter (min_pushes_per_key + 1 letters):
        for i in range(1, min_pushes_per_key + 2):
            if extra_letters > 0:
                total_pushes += i
                extra_letters -= 1
        
        # For the remaining keys with exactly min_pushes_per_key letters:
        for i in range(1, min_pushes_per_key + 1):
            total_pushes += i * (num_keys - extra_letters)
            num_keys -= 1
        
        return total_pushes
