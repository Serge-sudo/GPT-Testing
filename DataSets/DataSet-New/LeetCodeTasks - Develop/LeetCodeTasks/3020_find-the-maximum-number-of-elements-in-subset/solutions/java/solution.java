import java.util.Arrays;
import java.util.HashMap;

class Solution {
    public int maximumLength(int[] nums) {
        // Frequency map for counting occurrences of each number
        HashMap<Integer, Integer> count = new HashMap<>();
        
        // Fill the frequency map
        for (int num : nums) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }
        
        // Sorting the array allows for simpler linear traversal and manipulation
        Arrays.sort(nums);
        
        int result = 0;
        
        // Iterate from largest to smallest to handle the x^k to x^0 sequence
        for (int i = nums.length - 1; i >= 0; i--) {
            int current = nums[i];
            if (count.get(current) == 0) continue; // skip if already considered
            
            // Attempt to form the sequence x, x^2, x^4,..., x^k
            int maxLength = 0;
            int value = current;
            int steps = 0;
            while (true) {
                // Decrement count of current value (using it)
                int available = count.get(value);
                if (available > 0) {
                    count.put(value, available - 1);
                    maxLength++;
                } else {
                    // If not available, break
                    break;
                }
                
                // Check if next value in the pattern exists, i.e., value^2
                if ((long)value * value > Integer.MAX_VALUE) break; // prevent overflow
                value *= value;
                steps++;
            }
            
            // The maximum length of such a sequence found
            result = Math.max(result, maxLength);
        }
        
        return result;
    }
}
