class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        from collections import Counter

        # Count frequencies of each character in the word
        freq = Counter(word)

        # Get the list of frequencies of each character
        counts = list(freq.values())

        # Number of characters to delete to make the word k-special
        to_delete = 0

        # Work with the sorted frequency list
        counts.sort()
        n = len(counts)

        # Use a two-pointer approach to find the minimal deletions
        left = 0
        right = 0
        min_deletions = float('inf')
        current_sum = 0

        # Move the right pointer to expand the window
        while right < n:
            while right < n and (right == left or counts[right] - counts[left] <= k):
                current_sum += counts[right]
                right += 1
            # Calculate the number of deletions for the current valid range
            # Target frequency is based on the smallest frequency in the window (counts[left])
            # All frequencies should be between counts[left] and counts[left] + k
            max_valid_freq = counts[left] + k
            target_sum = (right - left) * max_valid_freq
            min_deletions = min(min_deletions, current_sum - target_sum)
            
            # Slide the left pointer to reduce the window size
            current_sum -= counts[left]
            left += 1
        
        return sum(counts) - (current_sum + min_deletions)
