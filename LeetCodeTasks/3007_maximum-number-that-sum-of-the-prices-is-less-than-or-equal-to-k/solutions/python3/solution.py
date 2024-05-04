class Solution:
    def findMaximumNumber(self, k: int, x: int) -> int:
        accumulated_price = 0
        num = 0

        while True:
            num += 1
            current_price = 0
            shift = x
            # Count set bits in positions x, 2x, 3x, etc.
            while shift <= num.bit_length():
                if (num & (1 << (shift - 1))) != 0:
                    current_price += 1
                shift += x

            accumulated_price += current_price
            
            # Stop when accumulated price exceeds k
            if accumulated_price > k:
                return num - 1  # The last number that was still cheap
