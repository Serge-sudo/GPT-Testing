class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        lower_case = set()
        upper_case = set()
        for char in word:
            if char.islower():
                lower_case.add(char)
            else:
                upper_case.add(char.upper())
        
        return len(lower_case.intersection(upper_case))
