#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    long long maximumSubarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, std::pair<long long, long long>> minMaxSum;
        long long currentSum = 0;
        long long maxGoodSubarraySum = 0;
        bool foundGoodSubarray = false;

        // To handle the case where we might start a good subarray from index 0
        minMaxSum[0] = {0, 0};

        for (int i = 0; i < nums.size(); ++i) {
            currentSum += nums[i];
            int target1 = nums[i] + k;  // looking for nums[i] - k in prefix sums
            int target2 = nums[i] - k;  // looking for nums[i] + k in prefix sums

            if (minMaxSum.count(target1)) {
                foundGoodSubarray = true;
                maxGoodSubarraySum = std::max(maxGoodSubarraySum, currentSum - minMaxSum[target1].first);
            }
            if (minMaxSum.count(target2)) {
                foundGoodSubarray = true;
                maxGoodSubarraySum = std::max(maxGoodSubarraySum, currentSum - minMaxSum[target2].first);
            }

            // We need to keep track of the smallest sum for each unique nums[i] seen so far
            if (!minMaxSum.count(nums[i])) {
                minMaxSum[nums[i]] = {currentSum, currentSum};
            } else {
                minMaxSum[nums[i]].first = std::min(minMaxSum[nums[i]].first, currentSum);
                minMaxSum[nums[i]].second = std::max(minMaxSum[nums[i]].second, currentSum);
            }
        }

        return foundGoodSubarray ? maxGoodSubarraySum : 0;
    }
};
