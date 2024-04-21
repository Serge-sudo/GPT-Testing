class Solution:
    def myAtoi(self, s: str) -> int:
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31
        
        i = 0
        n = len(s)
        result = 0
        negative = False
        
        # Step 1: Skip whitespaces
        while i < n and s[i] == ' ':
            i += 1
        
        # Step 2: Check the sign
        if i < n and (s[i] == '-' or s[i] == '+'):
            negative = s[i] == '-'
            i += 1
        
        # Step 3: Read in the number
        while i < n and s[i].isdigit():
            digit = int(s[i])
            # Step 4 & 5: Convert these digits into an integer and handle overflow
            if result > (INT_MAX - digit) // 10:
                return INT_MIN if negative else INT_MAX
            result = result * 10 + digit
            i += 1
        
        # Apply the negative sign if necessary
        return -result if negative else result
