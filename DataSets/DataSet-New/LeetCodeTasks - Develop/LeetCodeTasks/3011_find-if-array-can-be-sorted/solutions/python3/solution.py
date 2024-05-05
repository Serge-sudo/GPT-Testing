import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public boolean canSortArray(int[] nums) {
        Map<Integer, List<Integer>> bitMap = new HashMap<>();
        for (int num : nums) {
            int bits = Integer.bitCount(num);
            if (!bitMap.containsKey(bits)) {
                bitMap.put(bits, new ArrayList<>());
            }
            bitMap.get(bits).add(num);
        }
        
        List<Integer> sortedNums = new ArrayList<>();
        for (List<Integer> group : bitMap.values()) {
            Collections.sort(group);
            sortedNums.addAll(group);
        }
        
        Collections.sort(sortedNums);
        int index = 0;
        
        for (int bits : bitMap.keySet()) {
            List<Integer> group = bitMap.get(bits);
            Collections.sort(group);
            for (int num : group) {
                if (num != sortedNums.get(index)) {
                    return false;
                }
                index++;
            }
        }
        return true;
    }
}
