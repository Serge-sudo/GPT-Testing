#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int gcd_result = nums[0];
        for (int num : nums) {
            gcd_result = gcd(gcd_result, num);
            if (gcd_result == 1) return 1;
        }
        return gcd_result == 1 ? 1 : 2;
    }
};
