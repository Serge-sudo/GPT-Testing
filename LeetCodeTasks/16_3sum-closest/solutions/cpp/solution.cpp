#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int closestSum = INT_MAX;
        int smallestDiff = INT_MAX;

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                int currentDiff = abs(currentSum - target);

                if (currentDiff < smallestDiff) {
                    smallestDiff = currentDiff;
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    ++left;
                } else if (currentSum > target) {
                    --right;
                } else {
                    return target;  // Best possible case
                }
            }
        }
        return closestSum;
    }
};
