#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    long long minOperationsToMakeMedianK(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int medianIndex = n / 2;
        long long operations = 0;
        
        // If the array has an even number of elements, choose the higher middle element
        if (n % 2 == 0) {
            medianIndex = n / 2;
        } else {
            medianIndex = n / 2;
        }
        
        // Calculate the number of operations needed
        for (int i = 0; i < n; i++) {
            operations += std::abs(nums[i] - k);
        }
        
        return operations;
    }
};
