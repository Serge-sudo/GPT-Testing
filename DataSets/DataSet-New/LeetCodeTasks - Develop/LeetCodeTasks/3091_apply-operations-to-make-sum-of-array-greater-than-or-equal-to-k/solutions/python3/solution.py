class Solution:
    def minOperations(self, k: int) -> int:
        from heapq import heappush, heappop
        
        if k == 1:
            return 0
        
        ops = 0
        current_sum = 1
        max_heap = [-1]  # Use a max heap to efficiently get the largest element
        
        while current_sum < k:
            largest = -heappop(max_heap)
            if current_sum + largest >= k:
                # We can reach or exceed k by duplicating the largest number
                return ops + 1
            
            # We double the largest element by duplicating it and adding the original value to the sum
            heappush(max_heap, -largest)
            heappush(max_heap, -largest)
            current_sum += largest
            ops += 1
        
        return ops
