import java.util.*;

class Solution {
    public int minimumArrayLength(int[] nums) {
        TreeSet<Integer> set = new TreeSet<>();
        for (int num : nums) {
            if (num > 0) {
                set.add(num);
            }
        }
        while (set.size() > 1) {
            int max = set.last();
            set.remove(max);
            int secondMax = set.last();
            set.remove(secondMax);
            set.add(max % secondMax);
        }
        return set.isEmpty() ? 0 : set.first();
    }
}
