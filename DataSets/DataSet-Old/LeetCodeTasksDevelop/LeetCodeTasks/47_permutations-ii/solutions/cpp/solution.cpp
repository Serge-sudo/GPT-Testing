#include <vector>
#include <algorithm>

class Solution {
public:
    void backtrack(std::vector<int>& nums, int start, std::vector<std::vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        std::unordered_set<int> seen;
        for (int i = start; i < nums.size(); ++i) {
            if (seen.insert(nums[i]).second) {
                std::swap(nums[start], nums[i]);
                backtrack(nums, start + 1, result);
                std::swap(nums[start], nums[i]);
            }
        }
    }

    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());  // Sort to make sure duplicates are adjacent
        backtrack(nums, 0, result);
        return result;
    }
};
