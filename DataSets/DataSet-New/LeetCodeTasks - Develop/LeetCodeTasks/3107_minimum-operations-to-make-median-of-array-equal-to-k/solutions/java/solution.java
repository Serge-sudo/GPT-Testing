class Solution {
    public long minOperationsToMakeMedianK(int[] nums, int k) {
        int n = nums.length;
        int medianIndex = (n - 1) / 2; // This is the index of the median in 0-based index array
        long totalOps = 0;
        
        // Sort the array to determine the current median's position
        Arrays.sort(nums);
        
        // Calculate the total number of operations required to make the median equal to k
        for (int i = medianIndex; i < n; i++) {
            totalOps += Math.abs(nums[i] - k);
        }
        return totalOps;
    }
}
