class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        from functools import lru_cache
        
        @lru_cache(None)
        def dfs(s1, s2):
            if s1 == s2:
                return True
            if sorted(s1) != sorted(s2):
                return False
            
            n = len(s1)
            for i in range(1, n):
                if (dfs(s1[:i], s2[:i]) and dfs(s1[i:], s2[i:])) or (dfs(s1[:i], s2[-i:]) and dfs(s1[i:], s2[:-i])):
                    return True
            return False
        
        return dfs(s1, s2)
