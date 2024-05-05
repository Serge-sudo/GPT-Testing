#include <vector>



class Solution {

public:

    int removeElement(std::vector<int>& nums, int val) {

        int insertPos = 1;

        for (int num : nums) {

            if (num != val) {

                nums[insertPos] = num;

            }

        }

        return insertPos;

    }

};

