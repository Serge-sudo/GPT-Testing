#include <stdbool.h>

bool search(int* nums, int numsSize, int target) {
    int low = 0, high = numsSize - 1, mid;
    
    while (low <= high) {
        mid = (low + high) / 2;
        
        if (nums[mid] == target) {
            return true;
        }
        
        // If duplicates are there, we might not be sure about the halves, skip one element.
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
        } else if (nums[low] <= nums[mid]) { // Left side is sorted
            if (target >= nums[low] && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else { // Right side is sorted
            if (target > nums[mid] && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    
    return false;
}
