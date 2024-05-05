#include <vector>

using namespace std;

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long total = 0;
        int count = 1;
        
        for (int i = 1; i <= nums.size(); ++i) {
            if (i < nums.size() && nums[i] != nums[i - 1]) {
                ++count;
            } else {
                total += (long long) count * (count + 1) / 2;
                count = 1;
            }
        }
        
        return total;
    }
};
