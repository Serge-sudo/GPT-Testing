class Solution:
    def maximumSubarraySum(self, nums: list, k: int) -> int:
        from collections import defaultdict
        
        # Map to store sums with the keys as the target value (nums[i] - k and nums[i] + k)
        value_to_indices = defaultdict(list)
        max_sum = float('-inf')
        current_sum = 0

        # Process each number in the array
        for i, num in enumerate(nums):
            current_sum += num
            # Check for good subarray starting point by matching with nums[i] - k and nums[i] + k
            target1 = num - k
            target2 = num + k
            if target1 in value_to_indices:
                for sum_val in value_to_indices[target1]:
                    max_sum = max(max_sum, current_sum - sum_val)
            if target2 in value_to_indices:
                for sum_val in value_to_indices[target2]:
                    max_sum = max(max_sum, current_sum - sum_val)
            # Store current sum in map for future reference with this as the ending point
            value_to_indices[num].append(current_sum)

        return max_sum if max_sum != float('-inf') else 0
