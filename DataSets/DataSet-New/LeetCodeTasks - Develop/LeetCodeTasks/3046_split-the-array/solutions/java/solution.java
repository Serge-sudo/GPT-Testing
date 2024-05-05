import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean isPossibleToSplit(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }
        
        int n = nums.length / 2;
        int needTwo = 0;
        
        for (int count : freq.values()) {
            if (count == 1) {
                n--;
            } else if (count >= 2) {
                needTwo++;
                n -= 2;
            }
            if (n <= 0) break;
        }
        
        return n <= 0 && needTwo >= n;
    }
}
