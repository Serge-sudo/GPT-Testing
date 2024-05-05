class Solution:
    def getSmallestString(self, s: str, k: int) -> str:
        def cyclic_distance(c1, c2):
            return min(abs(ord(c1) - ord(c2)), 26 - abs(ord(c1) - ord(c2)))
        
        n = len(s)
        t = list(s)
        
        for i in range(n):
            # Try to convert s[i] to 'a' if possible within the remaining cost k
            if k > 0:
                # Calculate minimum distance to 'a'
                dist = cyclic_distance(s[i], 'a')
                if dist <= k:
                    t[i] = 'a'
                    k -= dist
        
        return ''.join(t)
