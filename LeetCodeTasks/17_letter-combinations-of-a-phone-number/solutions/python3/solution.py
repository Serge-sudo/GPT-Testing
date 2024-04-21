from typing import List

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        
        phone_map = {
            '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', 
            '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'
        }
        
        def backtrack(index: int, path: str):
            if index == len(digits):
                combinations.append(path)
                return
            letters = phone_map[digits[index]]
            for letter in letters:
                backtrack(index + 1, path + letter)
                
        combinations = []
        backtrack(0, "")
        return combinations
