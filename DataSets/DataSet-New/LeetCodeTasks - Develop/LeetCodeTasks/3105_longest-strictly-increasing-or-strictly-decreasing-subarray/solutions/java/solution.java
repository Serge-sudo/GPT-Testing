class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        if (nums.length == 1) return 1;

        int maxLength = 1;
        int currentLength = 1;

        // Check for strictly increasing
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i - 1]) {
                currentLength++;
                maxLength = Math.max(maxLength, currentLength);
            } else {
                currentLength = 1;
            }
        }

        // Reset current length for strictly decreasing check
        currentLength = 1;

        // Check for strictly decreasing
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < nums[i - 1]) {
                currentLength++;
                maxLength = Math.max(maxLength, currentLength);
            } else {
                currentLength = 1;
            }
        }

        return maxLength;
    }
}
