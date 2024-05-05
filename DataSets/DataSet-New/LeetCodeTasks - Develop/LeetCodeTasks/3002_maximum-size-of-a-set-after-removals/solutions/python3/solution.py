from collections import Counter
from heapq import heappush, heappop

class Solution:
    def maximumSetSize(self, nums1: list[int], nums2: list[int]) -> int:
        n = len(nums1)
        k = n // 2
        
        # Count frequencies of elements in both arrays
        count1 = Counter(nums1)
        count2 = Counter(nums2)
        
        # Use min-heaps to determine which elements to remove
        # to maximize the number of unique elements in the final set
        heap1 = []
        heap2 = []
        
        # We need to store -count because we want to create a max-heap using a min-heap
        for num, cnt in count1.items():
            heappush(heap1, (-cnt, num))
        
        for num, cnt in count2.items():
            heappush(heap2, (-cnt, num))
        
        # Remove the k most frequent elements from each heap
        removed1 = set()
        removed2 = set()
        
        # Remove elements from nums1's heap
        for _ in range(k):
            if heap1:
                cnt, num = heappop(heap1)
                removed1.add(num)
                if -cnt > 1:
                    heappush(heap1, (cnt + 1, num))  # Decrease count and push back
        
        # Remove elements from nums2's heap
        for _ in range(k):
            if heap2:
                cnt, num = heappop(heap2)
                removed2.add(num)
                if -cnt > 1:
                    heappush(heap2, (cnt + 1, num))  # Decrease count and push back
        
        # Calculate the maximum size of set s
        remaining1 = [num for num in nums1 if num not in removed1]
        remaining2 = [num for num in nums2 if num not in removed2]
        result_set = set(remaining1 + remaining2)
        
        return len(result_set)
