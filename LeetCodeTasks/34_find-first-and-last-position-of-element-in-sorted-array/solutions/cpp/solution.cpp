#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        int left = 0, right = nums.size() - 1;
        
        // Find the first occurrence of target
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                // Move leftwards to find the start
                if (mid == 0 || nums[mid - 1] != target) {
                    result[0] = mid;
                    break;
                } else {
                    right = mid - 1;
                }
            }
        }
        
        left = 0;
        right = nums.size() - 1;
        
        // Find the last occurrence of target
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                // Move rightwards to find the end
                if (mid == nums.size() - 1 || nums[mid + 1] != target) {
                    result[1] = mid;
                    break;
                } else {
                    left = mid + 1;
                }
            }
        }
        
        return result;
    }
};
