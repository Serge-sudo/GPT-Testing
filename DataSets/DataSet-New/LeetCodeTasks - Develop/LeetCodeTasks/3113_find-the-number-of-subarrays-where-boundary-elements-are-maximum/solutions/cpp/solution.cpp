#include <vector>
#include <unordered_map>

class Solution {
public:
    long long numberOfSubarrays(std::vector<int>& nums) {
        long long count = 0;
        std::unordered_map<int, std::vector<int>> positions;

        // Store positions of each element
        for (int i = 0; i < nums.size(); i++) {
            positions[nums[i]].push_back(i);
        }

        // Calculate the subarrays where the first and last elements are the maximums
        for (const auto& entry : positions) {
            const auto& indices = entry.second;
            for (int i = 0; i < indices.size(); i++) {
                int start = indices[i];
                for (int j = i; j < indices.size(); j++) {
                    int end = indices[j];
                    if (start == end) {
                        count++;  // Single element subarray
                    } else {
                        // Check if all elements between start and end are less than or equal to nums[start]
                        bool valid = true;
                        for (int k = start + 1; k < end; k++) {
                            if (nums[k] > nums[start]) {
                                valid = false;
                                break;
                            }
                        }
                        if (valid) count++;
                    }
                }
            }
        }

        return count;
    }
};
