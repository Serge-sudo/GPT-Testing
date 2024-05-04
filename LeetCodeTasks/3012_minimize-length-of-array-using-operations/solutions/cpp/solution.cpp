#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        while(nums.size() > 1) {
            sort(nums.begin(), nums.end());
            int remainder = nums.back() % nums[nums.size() - 2];
            nums.pop_back();
            nums.pop_back();
            if(remainder != 0)
                nums.push_back(remainder);
        }
        return nums.size();
    }
};
