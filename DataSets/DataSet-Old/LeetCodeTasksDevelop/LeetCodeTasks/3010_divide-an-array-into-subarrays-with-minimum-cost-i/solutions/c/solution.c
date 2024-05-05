class Solution:
    def beautifulIndices(self, s: str, a: str, b: str, k: int) -> list[int]:
        from bisect import bisect_left, bisect_right

        # Helper function to find all starting indices of substring `sub` in string `s`
        def find_indices(s, sub):
            start = 0
            indices = []
            while True:
                start = s.find(sub, start)
                if start == -1:
                    break
                indices.append(start)
                start += 1
            return indices
        
        indices_a = find_indices(s, a)
        indices_b = find_indices(s, b)
        
        beautiful_indices = []
        
        # Check each index of a if it can be called beautiful
        for i in indices_a:
            # We want to find if there exists j in indices_b such that |i - j| <= k
            # Using binary search to find the first index that could be within k distance from i
            low = bisect_left(indices_b, i - k)
            high = bisect_right(indices_b, i + k) - 1
            
            if low <= high:
                beautiful_indices.append(i)
        
        return beautiful_indices
