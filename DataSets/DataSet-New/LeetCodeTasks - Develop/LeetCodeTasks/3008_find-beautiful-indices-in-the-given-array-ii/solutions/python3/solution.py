class Solution:
    def beautifulIndices(self, s: str, a: str, b: str, k: int) -> list:
        from bisect import bisect_left, bisect_right

        n = len(s)
        len_a = len(a)
        len_b = len(b)
        
        # Function to find all starting indices of the substring sub in string s
        def find_substring_indices(sub):
            indices = []
            start = 0
            while True:
                start = s.find(sub, start)
                if start == -1:
                    break
                indices.append(start)
                start += 1
            return indices

        # Finding all starting indices for both strings a and b
        indices_a = find_substring_indices(a)
        indices_b = find_substring_indices(b)

        beautiful_indices = []

        for i in indices_a:
            # Check if there exists an index j for b such that |i - j| <= k
            # Using binary search to find the range of indices_b that satisfies |i - j| <= k
            # Which are in the range [i - k, i + k]
            low = bisect_left(indices_b, i - k)
            high = bisect_right(indices_b, i + k)
            
            # If there are indices in the range, then index i is beautiful
            if low < high:
                beautiful_indices.append(i)

        return beautiful_indices
