from heapq import heappush, heappop

class Solution:
    def findKthSmallest(self, coins: list[int], k: int) -> int:
        heap = []
        # Initialize the heap with the first multiple of each coin
        for coin in coins:
            heappush(heap, coin)
        
        kth_smallest = 0
        
        for _ in range(k):
            # Pop the smallest element from the heap
            kth_smallest = heappop(heap)
            # Only push the next multiple of the coin if the coin is the base of the popped element
            for coin in coins:
                next_val = kth_smallest + coin
                heappush(heap, next_val)
                # We only consider the next step for each coin from its own sequence
                if kth_smallest % coin == 0:
                    break
        
        return kth_smallest
