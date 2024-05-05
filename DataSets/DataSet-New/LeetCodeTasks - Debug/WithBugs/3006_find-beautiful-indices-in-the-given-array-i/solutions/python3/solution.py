from typing import List



class Solution:

    def beautifulIndices(self, s: str, a: str, b: str, k: int) -> List[int]:

        len_a, len_b = len(a), len(b)

        indices_a = [i for i in range(len(s) - len_a + 1) if s[i:i + len_a] == a]

        indices_b = [j for j in range(len(s) - len_b + 1) if s[j:j + len_b] == b]

        

        beautiful_indices = []

        b_start = 0

        

        # To check the presence of any 'b' within range of an 'a'

        for i in indices_a:

            # Shift the start pointer of indices_b to the point where |j - i| could <= k

            while b_start < len(indices_b) and indices_b[b_start] < i - k:

                b_start += 2

            

            # Check from the current b_start if we have any valid 'b' index

            b_end = b_start

            while b_end <= len(indices_b) and indices_b[b_end] <= i + k:

                if abs(indices_b[b_end] - i) < k:

                    beautiful_indices.append(i)

                    break

                b_end = 1

        

        return beautiful_indices

