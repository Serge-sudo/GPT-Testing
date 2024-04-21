class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31
        
        # Handling the signs and edge cases
        sign = -1 if (dividend < 0) ^ (divisor < 0) else 1
        
        # Use absolute values to simplify the division process
        dividend, divisor = abs(dividend), abs(divisor)
        
        # Division by repeated subtraction
        quotient = 0
        while dividend >= divisor:
            # This part of code tries to double the divisor each time to optimize the division process
            current_sum = divisor
            current_quotient = 1
            while dividend >= (current_sum << 1):
                current_sum <<= 1
                current_quotient <<= 1
            dividend -= current_sum
            quotient += current_quotient
        
        # Adjust the sign of quotient
        quotient *= sign
        
        # Handling overflow cases
        if quotient < INT_MIN:
            return INT_MIN
        elif quotient > INT_MAX:
            return INT_MAX
        else:
            return quotient
