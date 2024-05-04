class Solution:
    def maxPartitionsAfterOperations(self, s: str, k: int) -> int:
        from collections import defaultdict, deque
        
        # Function to calculate the number of partitions without any modification
        def count_partitions(s):
            n = len(s)
            i = 0
            parts = 0
            while i < n:
                char_count = defaultdict(int)
                distinct = 0
                j = i
                while j < n and (distinct < k or (distinct == k and s[j] in char_count)):
                    if char_count[s[j]] == 0:
                        distinct += 1
                    char_count[s[j]] += 1
                    if distinct > k:
                        break
                    j += 1
                parts += 1
                i = j
            return parts
        
        # Early exit: if k is large enough to take the whole string in one go
        if k >= 26:
            return 1
        
        # Calculate partitions without any changes
        max_partitions = count_partitions(s)
        
        # Optimally choosing to change one character to maximize partitions
        n = len(s)
        if n == 1:
            return 1
        
        # We'll try changing each character to any other character
        # and see if it improves the number of partitions
        for i in range(n):
            original_char = s[i]
            for c in range(26):
                new_char = chr(ord('a') + c)
                if new_char == original_char:
                    continue
                new_s = s[:i] + new_char + s[i+1:]
                max_partitions = max(max_partitions, count_partitions(new_s))
        
        return max_partitions
