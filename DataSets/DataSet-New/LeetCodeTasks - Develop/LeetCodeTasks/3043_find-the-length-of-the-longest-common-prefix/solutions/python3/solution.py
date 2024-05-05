class Solution:
    def longestCommonPrefix(self, arr1: list[int], arr2: list[int]) -> int:
        # Convert all numbers to strings
        arr1 = [str(num) for num in arr1]
        arr2 = [str(num) for num in arr2]
        
        # Sort arrays to make use of string properties in sorted arrays
        arr1.sort()
        arr2.sort()
        
        # Helper function to find longest common prefix of two strings
        def findLCP(s1, s2):
            min_len = min(len(s1), len(s2))
            lcp_length = 0
            for i in range(min_len):
                if s1[i] == s2[i]:
                    lcp_length += 1
                else:
                    break
            return lcp_length
        
        # Compare only the first and last elements after sorting, for each array
        max_prefix_length = 0
        if arr1 and arr2:
            # Check combinations of firsts and lasts that could give longest LCP
            candidates = [
                findLCP(arr1[0], arr2[0]),
                findLCP(arr1[0], arr2[-1]),
                findLCP(arr1[-1], arr2[0]),
                findLCP(arr1[-1], arr2[-1])
            ]
            max_prefix_length = max(candidates)
        
        return max_prefix_length
