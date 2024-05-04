import java.util.HashMap;

public class Solution {
    public int maxPartitionsAfterOperations(String s, int k) {
        int n = s.length();
        if (k >= 26) return 1; // With k>=26 we can always take the whole string as one partition.

        // Helper function to calculate the maximum partitions without changing any character
        int maxPartitions = maxPartitionsWithNoChanges(s, k);
        
        // Attempt to change each character and calculate the possible maximum partitions
        for (int i = 0; i < n; i++) {
            char original = s.charAt(i);
            for (char newChar = 'a'; newChar <= 'z'; newChar++) {
                if (original != newChar) {
                    String modifiedString = s.substring(0, i) + newChar + s.substring(i + 1);
                    maxPartitions = Math.max(maxPartitions, maxPartitionsWithNoChanges(modifiedString, k));
                }
            }
        }
        return maxPartitions;
    }

    // Function to calculate maximum partitions when no changes are allowed
    private int maxPartitionsWithNoChanges(String s, int k) {
        int count = 0;
        int i = 0;
        int n = s.length();
        while (i < n) {
            count++;
            int distinctCount = 0;
            HashMap<Character, Integer> charMap = new HashMap<>();
            int j = i;
            while (j < n && (distinctCount < k || charMap.containsKey(s.charAt(j)))) {
                char c = s.charAt(j);
                if (!charMap.containsKey(c)) {
                    distinctCount++;
                }
                charMap.put(c, charMap.getOrDefault(c, 0) + 1);
                if (distinctCount > k) break;
                j++;
            }
            i = j; // Move to next position after the current valid prefix
        }
        return count;
    }
}
