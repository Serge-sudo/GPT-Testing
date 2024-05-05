import java.util.HashMap;
import java.util.Map;

public class Solution {
    public long[] mostFrequentIDs(int[] nums, int[] freq) {
        int n = nums.length;
        long[] ans = new long[n];
        Map<Integer, Integer> idCounts = new HashMap<>();
        int maxFrequency = 0;

        for (int i = 0; i < n; i++) {
            int id = nums[i];
            int delta = freq[i];
            
            if (!idCounts.containsKey(id)) {
                idCounts.put(id, 0);
            }
            
            int newCount = idCounts.get(id) + delta;
            if (newCount <= 0) {
                idCounts.remove(id);
            } else {
                idCounts.put(id, newCount);
            }
            
            if (delta > 0) {
                if (newCount > maxFrequency) {
                    maxFrequency = newCount;
                }
            } else {
                if (idCounts.getOrDefault(id, 0) == 0 || maxFrequency > newCount) {
                    if (!idCounts.containsValue(maxFrequency)) {
                        maxFrequency = idCounts.values().stream().max(Integer::compare).orElse(0);
                    }
                }
            }

            ans[i] = maxFrequency;
        }
        return ans;
    }
}
