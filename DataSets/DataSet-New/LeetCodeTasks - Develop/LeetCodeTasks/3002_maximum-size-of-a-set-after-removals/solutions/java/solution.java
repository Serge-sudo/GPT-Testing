import java.util.*;

class Solution {
    public int maximumSetSize(int[] nums1, int[] nums2) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int num : nums1) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }
        for (int num : nums2) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }
        List<Integer> values = new ArrayList<>(count.values());
        Collections.sort(values, Collections.reverseOrder());
        int setSize = 0, removed = 0;
        for (int val : values) {
            setSize++;
            removed += val;
            if (removed >= nums1.length / 2 && removed >= nums2.length / 2) {
                break;
            }
        }
        return setSize;
    }
}
