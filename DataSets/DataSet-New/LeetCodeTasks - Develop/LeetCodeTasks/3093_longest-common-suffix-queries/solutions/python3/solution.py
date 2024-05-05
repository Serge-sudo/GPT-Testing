class Solution:
    def stringIndices(self, wordsContainer: list[str], wordsQuery: list[str]) -> list[int]:
        def common_suffix_length(s1, s2):
            min_len = min(len(s1), len(s2))
            count = 0
            for i in range(1, min_len + 1):
                if s1[-i] == s2[-i]:
                    count += 1
                else:
                    break
            return count
        
        ans = []
        
        for query in wordsQuery:
            max_len = -1
            best_index = -1
            shortest_length = float('inf')
            
            for i, container in enumerate(wordsContainer):
                suffix_len = common_suffix_length(query, container)
                
                if suffix_len > max_len or (suffix_len == max_len and len(container) < shortest_length):
                    max_len = suffix_len
                    best_index = i
                    shortest_length = len(container)
                elif suffix_len == max_len and len(container) == shortest_length:
                    if i < best_index:
                        best_index = i
            
            ans.append(best_index)
        
        return ans
