import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int maxPartitionsAfterOperations(String s, int k) {
        if (k == 0) return s.length();

        int n = s.length();
        int maxPartitions = 0;

        // Helper function to count maximum partitions for a given string
        java.util.function.ToIntFunction<String> getMaxPartitions = (str) -> {
            int count = 0;
            int start = 0;
            while (start < str.length()) {
                Map<Character, Integer> freq = new HashMap<>();
                int end = start;
                while (end < str.length() && freq.size() <= k) {
                    char ch = str.charAt(end);
                    freq.put(ch, freq.getOrDefault(ch, 0) + 1);
                    if (freq.size() > k) {
                        break;
                    }
                    end++;
                }
                count++;
                start = end;
            }
            return count;
        };

        // First check partitions without any change
        maxPartitions = getMaxPartitions.applyAsInt(s);

        // If k is 1, there is no point in changing a character to any other character
        if (k > 1) {
            // Try changing each character to each of 26 possible characters and calculate max partitions
            for (int i = 0; i < n; i++) {
                char originalChar = s.charAt(i);
                for (char newChar = 'a'; newChar <= 'z'; newChar++) {
                    if (newChar != originalChar) {
                        // Change s[i] to newChar
                        String modified = s.substring(0, i) + newChar + s.substring(i + 1);
                        maxPartitions = Math.max(maxPartitions, getMaxPartitions.applyAsInt(modified));
                    }
                }
            }
        }

        return maxPartitions;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.maxPartitionsAfterOperations("accca", 2)); // Example 1
        System.out.println(sol.maxPartitionsAfterOperations("aabaab", 3)); // Example 2
        System.out.println(sol.maxPartitionsAfterOperations("xxyz", 1)); // Example 3
    }
}
