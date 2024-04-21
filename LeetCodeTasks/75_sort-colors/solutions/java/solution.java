class Solution {
    public void sortColors(int[] nums) {
        int low = 0, mid = 0, high = nums.length - 1;
        while (mid <= high) {
            switch (nums[mid]) {
                case 0: // Red
                    swap(nums, low++, mid++);
                    break;
                case 1: // White
                    mid++;
                    break;
                case 2: // Blue
                    swap(nums, mid, high--);
                    break;
            }
        }
    }
    
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
