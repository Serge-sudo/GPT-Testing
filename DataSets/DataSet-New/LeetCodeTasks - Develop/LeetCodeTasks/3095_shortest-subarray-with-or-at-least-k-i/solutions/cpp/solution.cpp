#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumSubarrayLength(std::vector<int>& nums, int k) {
        int n = nums.size();
        int min_length = n + 1; // Start with a non-possible maximum length
        for (int start = 0; start < n; ++start) {
            int current_or = 0;
            for (int end = start; end < n; ++end) {
                current_or |= nums[end];
                if (current_or >= k) {
                    min_length = std::min(min_length, end - start + 1);
                    break; // Found the shortest subarray starting at `start`
                }
            }
        }
        return min_length <= n ? min_length : -1;
    }
};
