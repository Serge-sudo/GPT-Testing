class Solution:
    def lastNonEmptyString(self, s: str) -> str:
        from collections import deque
        
        s = deque(s)
        prev_s = ""
        
        while s:
            seen = set()
            prev_s = "".join(s)
            new_s = deque()
            for ch in s:
                if ch not in seen:
                    seen.add(ch)
                else:
                    new_s.append(ch)
            s = new_s
            
        return prev_s
