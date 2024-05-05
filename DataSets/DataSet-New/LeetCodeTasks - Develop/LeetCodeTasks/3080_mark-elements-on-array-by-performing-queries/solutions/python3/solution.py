class Solution:
    def unmarkedSumArray(self, nums: list[int], queries: list[list[int]]) -> list[int]:
        from sortedcontainers import SortedList
        
        n = len(nums)
        marked = [False] * n
        answer = []
        unmarked_values = SortedList()
        
        # Initialize the unmarked values sorted list
        for value in nums:
            unmarked_values.add(value)
        
        for index, k in queries:
            # Mark the element at the given index if it's not already marked
            if not marked[index]:
                marked[index] = True
                unmarked_values.remove(nums[index])
            
            # Mark the k smallest unmarked elements
            for _ in range(min(k, len(unmarked_values))):
                smallest_unmarked = unmarked_values.pop(0)
                smallest_unmarked_index = nums.index(smallest_unmarked)
                marked[smallest_unmarked_index] = True
            
            # Sum of unmarked elements after the current query
            answer.append(sum(unmarked_values))
        
        return answer
