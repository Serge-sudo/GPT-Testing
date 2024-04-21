class Solution {
    public boolean search(int[] nums, int target) {
        if (nums == null || nums.length == 0)
            return false;
        
        int left = 0;
        int right = nums.length - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return true;
            }
            
            // If left part is sorted
            if (nums[left] < nums[mid]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // If right part is sorted
            else if (nums[mid] < nums[right]) {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                // If nums[left] == nums[mid] == nums[right], we can't determine the sorted part
                // so just reduce the problem space
                if (nums[left] == nums[mid]) {
                    left++;
                }
                if (nums[right] == nums[mid]) {
                    right--;
                }
            }
        }
        
        return false;
    }
}
