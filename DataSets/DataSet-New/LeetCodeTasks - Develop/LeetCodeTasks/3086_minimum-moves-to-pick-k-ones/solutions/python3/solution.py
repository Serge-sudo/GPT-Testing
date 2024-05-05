from collections import deque

class Solution:
    def minimumMoves(self, nums: list[int], k: int, maxChanges: int) -> int:
        ones_positions = [i for i, val in enumerate(nums) if val == 1]
        num_ones = len(ones_positions)
        
        # Special cases where we need no movements at all
        if k == 0:
            return 0
        if num_ones == k:
            return 0
        
        # Using a sliding window to find the minimum cost to collect k ones
        min_moves = float('inf')
        prefix_sum = [0] * (num_ones + 1)
        
        for i in range(1, num_ones + 1):
            prefix_sum[i] = prefix_sum[i - 1] + ones_positions[i - 1]
        
        for i in range(num_ones - k + 1):
            j = i + k - 1
            mid_index = (i + j) // 2
            mid_value = ones_positions[mid_index]
            left_cost = mid_value * (mid_index - i) - (prefix_sum[mid_index] - prefix_sum[i])
            right_cost = (prefix_sum[j + 1] - prefix_sum[mid_index + 1]) - mid_value * (j - mid_index)
            current_cost = left_cost + right_cost
            
            # Adjust for the centering of the window
            if (k % 2) == 0:  # if k is even, adjust for non-symmetric window
                mid_value2 = ones_positions[mid_index + 1]
                left_cost2 = mid_value2 * (mid_index + 1 - i) - (prefix_sum[mid_index + 1] - prefix_sum[i])
                right_cost2 = (prefix_sum[j + 1] - prefix_sum[mid_index + 2]) - mid_value2 * (j - mid_index - 1)
                current_cost2 = left_cost2 + right_cost2
                current_cost = min(current_cost, current_cost2 - k // 2)  # Adjust to get real cost
            
            min_moves = min(min_moves, current_cost)
        
        # Incorporate maxChanges into the solution:
        if maxChanges > 0:
            # Since the game starts from picking up one '1' automatically and the ability to add ones
            min_moves = max(0, min_moves - maxChanges)
        
        return min_moves
