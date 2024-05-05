class Solution:
    def earliestSecondToMarkIndices(self, nums: List[int], changeIndices: List[int]) -> int:
        from collections import defaultdict
        
        # Determine the number of seconds required to reduce each index to zero
        needed_seconds = [x for x in nums]  # copies the initial values as the number of decrements needed
        
        # Track which indices have been marked
        marked = [False] * len(nums)
        
        # A map to track when we can first mark each index, initialized to a large number
        first_possible_mark = defaultdict(lambda: float('inf'))
        
        # Simulate the process by iterating over each second
        for s in range(len(changeIndices)):
            index_to_mark = changeIndices[s] - 1  # Convert to 0-based index
            if needed_seconds[index_to_mark] > 0:
                # If this index is still not zero, decrement the value at this index
                needed_seconds[index_to_mark] -= 1
            
            # If the value at this index is now zero and it has not been marked yet
            if needed_seconds[index_to_mark] == 0:
                # The first possible moment we can mark this index is the current second + 1
                first_possible_mark[index_to_mark] = min(first_possible_mark[index_to_mark], s + 1)
        
        # Determine the latest second by which all indices must be marked
        latest_mark_time = 0
        for i in range(len(nums)):
            if first_possible_mark[i] == float('inf'):
                # If there's any index that cannot be marked, return -1
                return -1
            latest_mark_time = max(latest_mark_time, first_possible_mark[i])
        
        # Return the latest time by which all indices have been marked
        return latest_mark_time
