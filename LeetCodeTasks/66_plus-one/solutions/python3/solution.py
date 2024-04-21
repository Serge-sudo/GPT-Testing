class Solution:
    def plusOne(self, digits: list[int]) -> list[int]:
        # We'll start from the last digit, which is the least significant
        n = len(digits)
        for i in range(n - 1, -1, -1):
            if digits[i] < 9:
                digits[i] += 1
                return digits
            digits[i] = 0
        
        # If all digits were 9, we end up here. We need to add a new digit '1' at the start.
        return [1] + digits
