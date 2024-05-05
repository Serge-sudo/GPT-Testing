from collections import defaultdict
from typing import List

class Solution:
    def mostFrequentIDs(self, nums: List[int], freq: List[int]) -> List[int]:
        count = defaultdict(int)  # Dictionary to keep track of ID counts
        max_freq = 0  # Track the maximum frequency at each step
        ans = []  # Result array to store the max frequency at each step
        
        for i in range(len(nums)):
            id_num = nums[i]
            change = freq[i]
            if change != 0:
                # Update the count of the current ID
                count[id_num] += change
                
                # If this ID's updated count is now the highest, update max_freq
                if count[id_num] > max_freq:
                    max_freq = count[id_num]
                
                # If the count for this ID drops to zero, we might need to find a new max
                if count[id_num] == 0:
                    del count[id_num]  # Remove the ID entirely if its count is zero
                    if max_freq > 0 and id_num in count and count[id_num] == max_freq:
                        # Recalculate the max frequency because the former max was this id
                        max_freq = max(count.values(), default=0)
                
                # If removing items and count drops below the current max
                elif change < 0 and count[id_num] + change < max_freq:
                    # Recalculate the max frequency in case we reduced the previous max
                    max_freq = max(count.values(), default=0)

            # Append the current max frequency or 0 if the collection is empty
            ans.append(max_freq if max_freq > 0 else 0)
        
        return ans
