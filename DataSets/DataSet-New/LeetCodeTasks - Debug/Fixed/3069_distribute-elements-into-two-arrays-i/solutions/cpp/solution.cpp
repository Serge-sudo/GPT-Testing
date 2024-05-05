#include <vector>

class Solution {
public:
    std::vector<int> resultArray(std::vector<int>& nums) {
        std::vector<int> arr1, arr2;

        arr1.push_back(nums[0]);  // Append nums[1] to arr1, since it's 1-indexed in the problem statement
        if (nums.size() > 1)
            arr2.push_back(nums[1]);  // Append nums[2] to arr2

        for (int i = 2; i < nums.size(); ++i) {
            if (arr1.back() > arr2.back())
                arr1.push_back(nums[i]);
            else
                arr2.push_back(nums[i]);
        }

        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};
