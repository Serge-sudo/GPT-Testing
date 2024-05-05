class Solution {
    public int minimumSubarrayLength(int[] nums, int k) {
        int minLen = Integer.MAX_VALUE;
        int currentOR = 0;
        int left = 0;
        
        for (int right = 0; right < nums.length; right++) {
            currentOR |= nums[right];
            
            while (currentOR >= k) {
                minLen = Math.min(minLen, right - left + 1);
                currentOR &= ~nums[left];
                left++;
            }
        }
        
        return minLen == Integer.MAX_VALUE ? -1 : minLen;
    }
}
