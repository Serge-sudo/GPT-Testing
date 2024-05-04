import java.util.*;

class Solution {
    public boolean canSortArray(int[] nums) {
        List<Integer>[] bitCount = new List[32];
        for (int i = 0; i < 32; i++) {
            bitCount[i] = new ArrayList<>();
        }
        
        for (int num : nums) {
            int count = Integer.bitCount(num);
            bitCount[count].add(num);
        }
        
        for (int i = 0; i < 31; i++) {
            Collections.sort(bitCount[i]);
        }
        
        for (int i = 1; i < nums.length; i++) {
            int count1 = Integer.bitCount(nums[i - 1]);
            int count2 = Integer.bitCount(nums[i]);
            if (count1 != count2) {
                return false;
            }
        }
        
        return true;
    }
}
