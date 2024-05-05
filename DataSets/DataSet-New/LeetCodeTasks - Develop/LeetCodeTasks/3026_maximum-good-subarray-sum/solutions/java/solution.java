import java.util.HashMap;

class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        HashMap<Integer, Long> map = new HashMap<>();
        long maxSum = 0;
        boolean found = false;
        
        for (int i = 0; i < nums.length; i++) {
            int target1 = nums[i] + k;
            int target2 = nums[i] - k;
            long currentSum = nums[i];
            
            if (map.containsKey(target1)) {
                long newSum = map.get(target1) + nums[i];
                if (newSum > maxSum) {
                    maxSum = newSum;
                    found = true;
                }
            }
            
            if (map.containsKey(target2)) {
                long newSum = map.get(target2) + nums[i];
                if (newSum > maxSum) {
                    maxSum = newSum;
                    found = true;
                }
            }
            
            map.put(nums[i], Math.max(map.getOrDefault(nums[i], 0L), currentSum));
        }
        
        return found ? maxSum : 0;
    }
}
