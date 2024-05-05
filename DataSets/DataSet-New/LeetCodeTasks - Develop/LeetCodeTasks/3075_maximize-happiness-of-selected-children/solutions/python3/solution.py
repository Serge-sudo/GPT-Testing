from typing import List
import heapq

class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        # Maximize heap for the largest values
        max_heap = []
        # Convert all happiness values into negative to use heapq as a max-heap
        for value in happiness:
            heapq.heappush(max_heap, -value)
        
        total_happiness = 0
        # We decrement the happiness and push back into heap to simulate the decrease
        for _ in range(k):
            # Take the maximum available happiness (it's negated to support max-heap)
            current_max = -heapq.heappop(max_heap)
            total_happiness += current_max
            # Decrement the happiness by 1 if it's positive
            next_happiness = max(0, current_max - 1)
            # Push it back into the heap negated
            heapq.heappush(max_heap, -next_happiness)
        
        return total_happiness
