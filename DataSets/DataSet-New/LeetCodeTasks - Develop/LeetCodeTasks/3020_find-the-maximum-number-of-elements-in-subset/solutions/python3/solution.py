from typing import List
from collections import Counter

class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        num_count = Counter(nums)
        sorted_nums = sorted(num_count.keys())
        max_length = 1  # At least any number can stand alone

        # Map to store the maximum length of sequence ending with a certain number
        max_seq_length = {}

        # For each number, see if it can be an element in a geometric progression sequence
        for num in sorted_nums:
            # Initialize with at least the count of the number itself
            max_seq_length[num] = num_count[num]
            # Check previous numbers that could lead to this number in the sequence
            x = num
            while x % 2 == 0:
                x //= 2
                if x in max_seq_length:
                    max_seq_length[num] = max(max_seq_length[num], max_seq_length[x] + num_count[num])
            # Update the global maximum
            max_length = max(max_length, max_seq_length[num])

        return max_length
