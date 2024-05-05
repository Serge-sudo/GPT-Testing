#include <vector>

class Solution {
public:
    int countMatchingSubarrays(std::vector<int>& nums, std::vector<int>& pattern) {
        int count = 0;
        int n = nums.size();
        int m = pattern.size();
        
        for (int i = 0; i <= n - m - 1; ++i) {
            bool matches = true;
            for (int k = 0; k < m; ++k) {
                if ((pattern[k] == 1 && !(nums[i + k + 1] > nums[i + k])) ||
                    (pattern[k] == 0 && !(nums[i + k + 1] == nums[i + k])) ||
                    (pattern[k] == -1 && !(nums[i + k + 1] < nums[i + k]))) {
                    matches = false;
                    break;
                }
            }
            if (matches) {
                ++count;
            }
        }
        
        return count;
    }
};
