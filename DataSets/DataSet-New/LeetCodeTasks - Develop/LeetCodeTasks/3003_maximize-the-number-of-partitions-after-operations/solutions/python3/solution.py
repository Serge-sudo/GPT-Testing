class Solution:
    def maxPartitionsAfterOperations(self, s: str, k: int) -> int:
        from collections import defaultdict
        
        def max_partitions(s: str) -> int:
            partitions = 0
            i = 0
            while i < len(s):
                count = defaultdict(int)
                distinct = 0
                j = i
                while j < len(s) and (distinct < k or (distinct == k and s[j] in count)):
                    if count[s[j]] == 0:
                        distinct += 1
                    count[s[j]] += 1
                    if distinct > k:
                        break
                    j += 1
                partitions += 1
                i = j
            return partitions
        
        # Check without any modification
        max_partitions_result = max_partitions(s)
        
        if k == 1:
            # If k == 1, each character change potentially maximizes partitions
            for i in range(len(s)):
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    if s[i] != c:
                        new_s = s[:i] + c + s[i+1:]
                        max_partitions_result = max(max_partitions_result, max_partitions(new_s))
            return max_partitions_result
        
        # Check by modifying each character once and replace it with every possible character
        for i in range(len(s)):
            original_char = s[i]
            for c in 'abcdefghijklmnopqrstuvwxyz':
                if c != original_char:
                    new_s = s[:i] + c + s[i+1:]
                    max_partitions_result = max(max_partitions_result, max_partitions(new_s))
        
        return max_partitions_result
