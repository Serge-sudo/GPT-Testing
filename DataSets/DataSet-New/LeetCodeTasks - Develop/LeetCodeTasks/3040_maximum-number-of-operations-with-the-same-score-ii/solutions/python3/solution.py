from collections import Counter
from typing import List

class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        # Counting all possible scores
        n = len(nums)
        score_count = Counter()
        for i in range(n // 2):
            score_front = nums[i] + nums[i + 1]  # First two elements from start
            score_back = nums[n - 1 - i] + nums[n - 2 - i]  # Last two elements from end
            score_cross = nums[i] + nums[n - 1 - i]  # First and last elements
            score_count[score_front] += 1
            if i != n - 2 - i:
                score_count[score_back] += 1
            score_count[score_cross] += 1

        # Finding the maximum number of operations with the same score
        max_operations = 0
        for score, count in score_count.items():
            max_operations = max(max_operations, count)

        return max_operations
