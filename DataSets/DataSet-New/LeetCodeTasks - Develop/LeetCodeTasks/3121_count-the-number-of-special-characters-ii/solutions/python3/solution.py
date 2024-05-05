class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        from collections import defaultdict
        
        first_upper = defaultdict(lambda: float('inf'))
        last_lower = defaultdict(lambda: float('-inf'))
        
        # Track the positions of first uppercase and last lowercase for each letter
        for i, char in enumerate(word):
            if 'a' <= char <= 'z':
                last_lower[char] = i
            elif 'A' <= char <= 'Z':
                first_upper[char.lower()] = min(first_upper[char.lower()], i)
        
        # Count how many special characters are there
        count = 0
        for c in last_lower:
            if last_lower[c] < first_upper[c]:
                count += 1
        
        return count
