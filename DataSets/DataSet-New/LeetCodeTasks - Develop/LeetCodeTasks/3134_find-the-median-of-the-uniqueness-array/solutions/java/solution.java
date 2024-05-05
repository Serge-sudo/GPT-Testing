import java.util.HashMap;
import java.util.TreeMap;

class Solution {
    public int medianOfUniquenessArray(int[] nums) {
        int n = nums.length;
        TreeMap<Integer, Integer> freqMap = new TreeMap<>();
        int[] prefixDistinctCount = new int[n + 1];

        for (int end = 0; end < n; end++) {
            HashMap<Integer, Integer> lastPosition = new HashMap<>();
            int distinct = 0;
            
            for (int start = end; start >= 0; start--) {
                int num = nums[start];
                if (!lastPosition.containsKey(num) || lastPosition.get(num) < start) {
                    distinct++;
                    lastPosition.put(num, end);
                }
                
                prefixDistinctCount[distinct]++;
            }
        }

        long totalCount = ((long) n * (n + 1)) / 2;
        long midCount = (totalCount + 1) / 2;
        
        long count = 0;
        for (int key : prefixDistinctCount) {
            count += key;
            if (count >= midCount) {
                return key;
            }
        }
        
        return -1;  // Should never reach here under correct circumstances
    }
}
