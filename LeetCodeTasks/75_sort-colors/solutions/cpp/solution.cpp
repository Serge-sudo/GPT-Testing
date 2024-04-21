#include <vector>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int zeroIndex = 0, twoIndex = nums.size() - 1, i = 0;
        while (i <= twoIndex) {
            if (nums[i] == 0) {
                std::swap(nums[i], nums[zeroIndex]);
                zeroIndex++;
                i++;
            } else if (nums[i] == 2) {
                std::swap(nums[i], nums[twoIndex]);
                twoIndex--;
            } else {
                i++;
            }
        }
    }
};
