#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    bool canSortArray(std::vector<int>& nums) {
        std::unordered_map<int, std::vector<int>> bitMap;
        
        for (int num : nums) {
            int bitCount = __builtin_popcount(num);
            bitMap[bitCount].push_back(num);
        }
        
        std::vector<int> sortedNums;
        
        for (auto& [_, group] : bitMap) {
            std::sort(group.begin(), group.end());
            sortedNums.insert(sortedNums.end(), group.begin(), group.end());
        }
        
        std::sort(nums.begin(), nums.end());
        
        return sortedNums == nums;
    }
};
