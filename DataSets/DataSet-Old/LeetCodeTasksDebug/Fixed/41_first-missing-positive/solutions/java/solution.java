class Solution {

    public int firstMissingPositive(int[] nums) {

        int n = nums.length;

        // Step 1: Replace non-positive numbers and numbers greater than n with 1
        boolean containsOne = false;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                containsOne = true;
            }
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }
        }

        // If one is not present, the answer must be 1
        if (!containsOne) return 1;

        // Step 2: Use index mapping to mark presence of elements
        for (int i = 0; i < n; i++) {
            int index = Math.abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }

        // Step 3: The first index with a positive number indicates the missing positive
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        // If all positions are filled, then answer is n + 1
        return n + 1;
    }
}
