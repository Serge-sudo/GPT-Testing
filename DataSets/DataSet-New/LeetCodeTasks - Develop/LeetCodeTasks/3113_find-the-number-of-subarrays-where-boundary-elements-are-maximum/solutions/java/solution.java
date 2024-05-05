class Solution {
    public long numberOfSubarrays(int[] nums) {
        long result = 0;
        int n = nums.length;
        
        // Find all occurrences of each value
        for (int i = 0; i < n; i++) {
            int max = nums[i];
            // Extend subarray to the right
            for (int j = i; j < n; j++) {
                max = Math.max(max, nums[j]);
                // Check if current subarray [i, j] satisfies the condition
                if (nums[i] == nums[j] && nums[i] == max) {
                    result++;
                }
            }
        }
        
        return result;
    }
}
