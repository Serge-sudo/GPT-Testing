from typing import List
from collections import Counter

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not words or not s:
            return []

        word_length = len(words[0])
        total_words_length = len(words) * word_length
        word_count = Counter(words)
        result_indices = []

        for i in range(word_length):
            left = i
            current_count = Counter()

            for right in range(i, len(s) - word_length + 1, word_length):
                word = s[right:right + word_length]
                current_count[word] += 1

                while current_count[word] > word_count[word]:
                    current_count[s[left:left + word_length]] -= 1
                    left += word_length

                if (right + word_length - left) == total_words_length:
                    result_indices.append(left)

        return result_indices
