class Solution:
    def shortestSubstrings(self, arr: list[str]) -> list[str]:
        from itertools import combinations
        
        def all_substrings(s):
            n = len(s)
            return [s[i:j] for i in range(n) for j in range(i + 1, n + 1)]
        
        n = len(arr)
        answer = [''] * n
        
        # Create a dictionary to hold all substrings of each string
        substrings = {i: all_substrings(arr[i]) for i in range(n)}
        
        # Attempt to find the shortest unique substring
        for i in range(n):
            found = False
            # Sort substrings by length and then lexicographically
            sorted_subs = sorted(set(substrings[i]), key=lambda x: (len(x), x))
            for sub in sorted_subs:
                is_unique = True
                # Check if this substring appears in any other string
                for j in range(n):
                    if i != j and sub in arr[j]:
                        is_unique = False
                        break
                if is_unique:
                    answer[i] = sub
                    found = True
                    break
            if not found:
                answer[i] = ''
        
        return answer
