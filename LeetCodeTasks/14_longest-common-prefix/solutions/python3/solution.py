from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        
        # Start with the first string in the array as the initial prefix
        prefix = strs[0]
        
        # Compare the prefix with each string in the array
        for s in strs:
            # Reduce the prefix until it matches the beginning of each string
            while not s.startswith(prefix):
                prefix = prefix[:-1]
                if prefix == "":
                    return ""
        
        return prefix
