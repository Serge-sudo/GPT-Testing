#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        std::vector<std::vector<int>> result;
        int i = 0;
        int start = newInterval[0];
        int end = newInterval[1];

        // Add all intervals ending before newInterval starts
        while (i < intervals.size() && intervals[i][1] < start) {
            result.push_back(intervals[i]);
            ++i;
        }

        // Merge all overlapping intervals to one considering newInterval
        while (i < intervals.size() && intervals[i][0] <= end) {
            start = std::min(start, intervals[i][0]);
            end = std::max(end, intervals[i][1]);
            ++i;
        }
        result.push_back({start, end});

        // Add all the rest
        while (i < intervals.size()) {
            result.push_back(intervals[i]);
            ++i;
        }

        return result;
    }
};
