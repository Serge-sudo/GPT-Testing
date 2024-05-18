class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        left = 0
        max_len = 0
        char_count = {}

        for right in range(len(s)):
            char_count[s[right]] = char_count.get(s[right], 0) + 1
            
            # Shrink the window until each character has at most two occurrences
            while any(c > 2 for c in char_count.values()):
                char_count[s[left]] -= 1
                if char_count[s[left]] == 0:
                    del char_count[s[left]]
                left += 1
            
            max_len = max(max_len, right - left + 1)

        return max_len
