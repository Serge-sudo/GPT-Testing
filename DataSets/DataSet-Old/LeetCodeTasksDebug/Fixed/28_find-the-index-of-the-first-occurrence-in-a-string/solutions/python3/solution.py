class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == "":
            return 0
        
        # Length of the needle
        needle_length = len(needle)
        
        # Loop through the haystack up to the point where the needle could still fit
        for i in range(len(haystack) - needle_length + 1):
            # Check if the substring from i to i + needle_length is the needle
            if haystack[i:i + needle_length] == needle:
                return i
        return -1
