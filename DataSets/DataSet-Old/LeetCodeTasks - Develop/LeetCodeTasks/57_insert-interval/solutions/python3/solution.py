class Solution:
    def insert(self, intervals: list[list[int]], newInterval: list[int]) -> list[list[int]]:
        merged = []
        i = 0
        # Add all the intervals ending before newInterval starts
        while i < len(intervals) and intervals[i][1] < newInterval[0]:
            merged.append(intervals[i])
            i += 1

        # Merge all overlapping intervals to one considering newInterval
        while i < len(intervals) and intervals[i][0] <= newInterval[1]:
            newInterval = [min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])]
            i += 1
        merged.append(newInterval)

        # Add all the rest
        while i < len(intervals):
            merged.append(intervals[i])
            i += 1

        return merged
