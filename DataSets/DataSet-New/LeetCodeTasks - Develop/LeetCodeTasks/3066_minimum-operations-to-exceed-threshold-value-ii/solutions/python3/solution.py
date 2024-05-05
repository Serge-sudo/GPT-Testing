import heapq

class Solution:
    def minOperations(self, nums: list[int], k: int) -> int:
        heapq.heapify(nums)
        operations = 0
        
        while nums[0] < k:
            if len(nums) < 2:
                return -1  # If somehow the prompt conditions are violated
            
            x = heapq.heappop(nums)
            y = heapq.heappop(nums)
            
            merged_value = min(x, y) * 2 + max(x, y)
            heapq.heappush(nums, merged_value)
            operations += 1
            
            if len(nums) == 1 and nums[0] < k:
                return -1  # No way to increase the value further if only one element remains
        
        return operations
