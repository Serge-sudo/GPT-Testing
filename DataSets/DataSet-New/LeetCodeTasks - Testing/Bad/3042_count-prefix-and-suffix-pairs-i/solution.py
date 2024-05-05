from typing import List



class Solution:

    def countPrefixSuffixPairs(self, words: List[str]) -> int:

        def isPrefixAndSuffix(str1: str, str2: str) -> bool:

            return str2.startswith(str1) or str2.endswith(str1)

        

        n = len(words)

        count = 0

        

        for i in range(n):

            for j in range(i, n):

                if isPrefixAndSuffix(words[j], words[i]):

                    count += 1

        

        return count

