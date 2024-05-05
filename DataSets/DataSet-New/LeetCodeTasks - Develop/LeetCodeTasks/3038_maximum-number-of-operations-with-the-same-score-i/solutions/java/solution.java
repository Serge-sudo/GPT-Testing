import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maxOperations(int[] nums) {
        Map<Integer, Integer> scoreCounts = new HashMap<>();
        int operations = 0;

        for (int i = 0; i < nums.length - 1; i += 2) {
            int score = nums[i] + nums[i + 1];
            scoreCounts.put(score, scoreCounts.getOrDefault(score, 0) + 1);
        }

        // Finding the maximum number of operations for the same score
        for (int count : scoreCounts.values()) {
            operations = Math.max(operations, count);
        }

        return operations;
    }
}
