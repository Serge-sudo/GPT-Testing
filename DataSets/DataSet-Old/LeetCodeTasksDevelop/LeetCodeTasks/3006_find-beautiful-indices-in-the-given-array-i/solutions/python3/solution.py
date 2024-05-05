class Solution:
    def beautifulIndices(self, s: str, a: str, b: str, k: int) -> list:
        n = len(s)
        len_a = len(a)
        len_b = len(b)
        
        # Find all start indices where substring a occurs
        indices_a = [i for i in range(n - len_a + 1) if s[i:i + len_a] == a]
        
        # Find all start indices where substring b occurs
        indices_b = [i for i in range(n - len_b + 1) if s[i:i + len_b] == b]
        
        # We will use two pointers to determine the validity of the distance
        j = 0
        beautiful_indices = []
        
        # For each index in indices_a, check if a valid index in indices_b exists within distance k
        for i in indices_a:
            # Move j to the leftmost index in indices_b that is within the range [i-k, i+k]
            while j < len(indices_b) and indices_b[j] < i - k:
                j += 1
            
            # Check if there is any j that satisfies the condition |i - j| <= k
            found = False
            for m in range(j, len(indices_b)):
                if abs(indices_b[m] - i) <= k:
                    beautiful_indices.append(i)
                    found = True
                    break
                if indices_b[m] > i + k:
                    break
        
        return beautiful_indices
