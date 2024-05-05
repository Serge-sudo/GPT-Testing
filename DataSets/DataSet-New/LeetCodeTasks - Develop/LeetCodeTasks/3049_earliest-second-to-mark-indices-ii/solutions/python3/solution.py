class Solution:
    def earliestSecondToMarkIndices(self, nums: list[int], changeIndices: list[int]) -> int:
        from collections import defaultdict

        n = len(nums)
        m = len(changeIndices)
        
        # Track required operations to zero-out each index
        ops_needed = [0] * (n + 1)
        for i in range(1, n + 1):
            ops_needed[i] = nums[i - 1]
        
        # Dictionary to keep count of the max occurrence second of each index in changeIndices
        last_possible = defaultdict(int)
        for second in range(1, m + 1):
            index = changeIndices[second - 1]
            last_possible[index] = second
        
        # Check if we can set all indices to zero using the "set to any value" operation by the last occurrence
        for i in range(1, n + 1):
            if i not in last_possible or last_possible[i] < ops_needed[i]:
                # If the index i cannot be set to zero by its last occurrence, it's impossible
                return -1
        
        # All indices can be zeroed by their respective last "set to any value" operations
        # After zeroing them, marking them takes at most one additional step per index
        # Hence, return the maximum time needed to zero-out and then immediately mark
        return max(last_possible.values())
