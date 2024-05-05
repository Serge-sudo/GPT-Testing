class Solution:
    def minimizeStringValue(self, s: str) -> str:
        from collections import Counter
        
        # We will replace the resulting array of characters
        res = list(s)
        # Keep count of occurrences of each character before each position
        count = Counter()
        
        for i in range(len(s)):
            if s[i] == '?':
                # Find the lexicographically smallest character that minimizes increase in cost
                # We choose the character that has appeared the least times to minimize the cost
                best_char = 'a'
                while best_char in count and count[best_char] > 0:
                    best_char = chr(ord(best_char) + 1)
                res[i] = best_char
                count[best_char] += 1
            else:
                # Use the existing character and update the count
                count[s[i]] += 1

        return ''.join(res)
