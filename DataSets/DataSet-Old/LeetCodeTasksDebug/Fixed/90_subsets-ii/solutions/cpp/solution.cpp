#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> currentSubset;
        std::sort(nums.begin(), nums.end());
        generateSubsets(0, nums, currentSubset, result);
        return result;
    }

    void generateSubsets(int index, std::vector<int>& nums, std::vector<int>& currentSubset, std::vector<std::vector<int>>& result) {
        result.push_back(currentSubset);

        for (int i = index; i < nums.size(); ++i) {
            if (i > index && nums[i] == nums[i - 1]) continue;

            currentSubset.push_back(nums[i]);
            generateSubsets(i + 1, nums, currentSubset, result);
            currentSubset.pop_back();
        }
    }
};
