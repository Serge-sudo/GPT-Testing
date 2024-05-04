from typing import List

class Solution:
    def beautifulIndices(self, s: str, a: str, b: str, k: int) -> List[int]:
        n = len(s)
        a_len = len(a)
        b_len = len(b)
        
        # Find all starting indices where 'a' occurs
        indices_a = [i for i in range(n - a_len + 1) if s[i:i + a_len] == a]
        # Find all starting indices where 'b' occurs
        indices_b = [i for i in range(n - b_len + 1) if s[i:i + b_len] == b]
        
        beautiful_indices = []
        j = 0  # pointer for indices_b
        
        # We use a two-pointer approach to find the beautiful indices for 'a'
        for i in indices_a:
            # Move the pointer j to the closest 'b' index >= i-k
            while j < len(indices_b) and indices_b[j] < i - k:
                j += 1
            
            # Check the condition within the range i + k
            temp_j = j
            while temp_j < len(indices_b) and indices_b[temp_j] <= i + k:
                if abs(indices_b[temp_j] - i) <= k:
                    beautiful_indices.append(i)
                    break
                temp_j += 1
        
        return beautiful_indices
