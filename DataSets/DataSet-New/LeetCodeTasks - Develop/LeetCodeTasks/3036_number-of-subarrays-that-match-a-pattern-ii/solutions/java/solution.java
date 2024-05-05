class Solution {
    public int countMatchingSubarrays(int[] nums, int[] pattern) {
        int count = 0;
        int m = pattern.length;
        int n = nums.length;

        // Loop through each possible starting index of a subarray of length m+1 in nums
        for (int i = 0; i <= n - m - 1; i++) {
            boolean matches = true;

            // Check each element of the pattern
            for (int k = 0; k < m; k++) {
                if ((pattern[k] == 1 && !(nums[i + k + 1] > nums[i + k])) ||
                    (pattern[k] == 0 && !(nums[i + k + 1] == nums[i + k])) ||
                    (pattern[k] == -1 && !(nums[i + k + 1] < nums[i + k]))) {
                    matches = false;
                    break;
                }
            }

            if (matches) {
                count++;
            }
        }
        return count;
    }
}
