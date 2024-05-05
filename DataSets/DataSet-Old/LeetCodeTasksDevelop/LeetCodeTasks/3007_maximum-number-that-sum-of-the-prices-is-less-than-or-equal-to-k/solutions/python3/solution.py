class Solution:
    def findMaximumNumber(self, k: int, x: int) -> int:
        # Helper function to calculate the price of a number
        def calculate_price(num: int) -> int:
            price = 0
            # Start from position x (one-based index), but shift to zero-based by subtracting 1
            pos = x - 1
            # Check each position `x, 2x, 3x, ...` and count set bits
            while pos < num.bit_length():
                if num & (1 << pos):
                    price += 1
                pos += x
            return price

        # We will use a binary search on the number `num` to find the maximum cheap number
        left, right = 1, k * x  # Upper bound heuristic, assuming each bit at `x, 2x, ...` contributes 1 to the price
        best_cheap_num = 0
        accumulated_price = 0
        
        # Binary search to find the max cheap number
        while left <= right:
            mid = (left + right) // 2
            # Calculate the accumulated price of `mid` by summing prices from 1 to `mid`
            temp_acc_price = 0
            for i in range(1, mid + 1):
                temp_acc_price += calculate_price(i)
            
            if temp_acc_price <= k:
                best_cheap_num = mid
                accumulated_price = temp_acc_price
                left = mid + 1
            else:
                right = mid - 1
        
        return best_cheap_num
