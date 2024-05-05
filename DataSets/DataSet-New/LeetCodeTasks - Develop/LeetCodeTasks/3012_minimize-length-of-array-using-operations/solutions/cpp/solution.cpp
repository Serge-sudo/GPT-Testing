#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int minimumArrayLength(std::vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        // Compute the gcd of all elements in the array
        int overall_gcd = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            overall_gcd = std::gcd(overall_gcd, nums[i]);
            if (overall_gcd == 1) return 1;  // Once GCD is 1, we cannot reduce further
        }

        // If GCD is not 1, we cannot reduce the array to a length less than 2
        return overall_gcd > 1 ? 2 : 1;
    }
};
