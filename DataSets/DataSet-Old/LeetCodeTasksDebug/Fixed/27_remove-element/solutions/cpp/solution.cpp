#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int insertPos = 0;

        for (int num : nums) {
            if (num != val) {
                nums[insertPos] = num;
                insertPos++;
            }
        }

        return insertPos;
    }
};
