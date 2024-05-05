from typing import List
from math import gcd

class Solution:
    def minimumArrayLength(self, nums: List[int]) -> int:
        # We start by finding the GCD of all numbers in the array
        current_gcd = nums[0]
        for num in nums[1:]:
            current_gcd = gcd(current_gcd, num)
            if current_gcd == 1:
                return 1  # Once the GCD is 1, we cannot reduce the array size below 1

        # If the GCD is not 1, then all numbers can be reduced to the GCD and operations can keep the GCD
        # In this case, all numbers are effectively the same, and operations will not change this.
        return 1 if current_gcd == 1 else 2
