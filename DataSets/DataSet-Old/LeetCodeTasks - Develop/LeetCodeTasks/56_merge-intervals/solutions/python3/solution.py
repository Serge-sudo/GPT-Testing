from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # First, sort the intervals by their start times
        intervals.sort(key=lambda x: x[0])

        # List to hold the merged intervals
        merged = []

        # Iterate through each interval
        for interval in intervals:
            # If the merged list is empty or there is no overlap, add the interval
            if not merged or merged[-1][1] < interval[0]:
                merged.append(interval)
            else:
                # There is an overlap, merge the current interval with the last one in merged
                merged[-1][1] = max(merged[-1][1], interval[1])

        return merged
