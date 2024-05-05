#include <vector>

class Solution {
public:
    int countMatchingSubarrays(std::vector<int>& nums, std::vector<int>& pattern) {
        int count = 0;
        int n = nums.size();
        int m = pattern.size();
        
        // Loop through each starting point where a subarray of length m + 1 can exist
        for (int i = 0; i <= n - m - 1; ++i) {
            bool matches = true;
            // Check each element in the pattern
            for (int j = 0; j < m; ++j) {
                if ((pattern[j] == 1 && nums[i + j] >= nums[i + j + 1]) ||
                    (pattern[j] == 0 && nums[i + j] != nums[i + j + 1]) ||
                    (pattern[j] == -1 && nums[i + j] <= nums[i + j + 1])) {
                    matches = false;
                    break;
                }
            }
            if (matches) {
                count++;
            }
        }
        
        return count;
    }
};
