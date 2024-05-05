import java.util.TreeMap;

public class Solution {
    public long[] unmarkedSumArray(int[] nums, int[][] queries) {
        int n = nums.length;
        int m = queries.length;
        long[] result = new long[m];

        boolean[] marked = new boolean[n];
        TreeMap<Integer, Integer> unmarkedValues = new TreeMap<>();

        // Fill TreeMap with initial values and their counts
        for (int num : nums) {
            unmarkedValues.put(num, unmarkedValues.getOrDefault(num, 0) + 1);
        }

        long totalUnmarkedSum = 0;
        for (int num : nums) {
            totalUnmarkedSum += num;
        }

        for (int i = 0; i < m; i++) {
            int index = queries[i][0];
            int k = queries[i][1];

            // Mark the element at index if not already marked
            if (!marked[index]) {
                marked[index] = true;
                int value = nums[index];
                int count = unmarkedValues.get(value);
                if (count == 1) {
                    unmarkedValues.remove(value);
                } else {
                    unmarkedValues.put(value, count - 1);
                }
                totalUnmarkedSum -= value;
            }

            // Mark the smallest unmarked elements (up to k)
            while (k > 0 && !unmarkedValues.isEmpty()) {
                var entry = unmarkedValues.firstEntry();
                int val = entry.getKey();
                int cnt = entry.getValue();

                int toMark = Math.min(k, cnt);
                k -= toMark;

                if (toMark == cnt) {
                    unmarkedValues.remove(val);
                } else {
                    unmarkedValues.put(val, cnt - toMark);
                }

                totalUnmarkedSum -= (long) val * toMark;
            }

            result[i] = totalUnmarkedSum;
        }

        return result;
    }
}
