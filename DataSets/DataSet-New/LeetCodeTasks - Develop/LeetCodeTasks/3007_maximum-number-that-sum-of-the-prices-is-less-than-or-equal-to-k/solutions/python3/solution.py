class Solution:
    def findMaximumNumber(self, k: int, x: int) -> int:
        accumulated_price = 0
        num = 0
        
        while accumulated_price <= k:
            num += 1
            current_price = 0
            index = x
            
            # Calculate the price for the current number `num`
            while index - 1 < num.bit_length():
                if num & (1 << (index - 1)):
                    current_price += 1
                index += x
            
            # Update the accumulated price
            accumulated_price += current_price
            
            # If the next number makes it exceed k, return current number
            if accumulated_price > k:
                return num
        
        # Fallback return, technically unreachable
        return num
