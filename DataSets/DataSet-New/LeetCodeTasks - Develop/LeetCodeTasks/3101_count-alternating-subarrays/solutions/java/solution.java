class Solution {
    public long countAlternatingSubarrays(int[] nums) {
        long totalAlternating = 0;
        int start = 0;
        
        while (start < nums.length) {
            int length = 1;
            while (start + length < nums.length && nums[start + length] != nums[start + length - 1]) {
                length++;
            }
            totalAlternating += ((long) length * (length + 1)) / 2;
            start += length;
        }
        
        return totalAlternating;
    }
}
