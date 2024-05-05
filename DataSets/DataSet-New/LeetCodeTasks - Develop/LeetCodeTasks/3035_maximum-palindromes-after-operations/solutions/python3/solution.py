class Solution:
    def maxPalindromesAfterOperations(self, words: list[str]) -> int:
        from collections import Counter
        
        # Count total frequencies of each character across all words
        total_char_count = Counter()
        for word in words:
            total_char_count += Counter(word)
        
        # Calculate maximum palindromes we can form based on character counts
        max_palindromes = 0
        odd_count = 0
        
        for count in total_char_count.values():
            max_palindromes += count // 2
            if count % 2 == 1:
                odd_count += 1
        
        # Max possible palindromes is number of pairs we can form + whether we can place a single odd character
        # each even count contributes to forming pairs, while each odd character can potentially start a new palindrome
        return min(len(words), max_palindromes // 2 + (odd_count > 0))
