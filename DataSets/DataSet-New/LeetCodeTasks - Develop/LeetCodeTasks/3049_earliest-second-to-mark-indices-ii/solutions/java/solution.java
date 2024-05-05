import java.util.*;

class Solution {
    public int earliestSecondToMarkIndices(int[] nums, int[] changeIndices) {
        int n = nums.length;
        int m = changeIndices.length;
        
        // Track minimum seconds required to make each index zero
        int[] earliestZero = new int[n + 1];
        Arrays.fill(earliestZero, Integer.MAX_VALUE);

        // Adjust indices in changeIndices for 1-indexed array
        for (int i = 0; i < m; i++) {
            changeIndices[i]--;
        }

        // Track the count of decrements still needed for each index
        int[] decrementsNeeded = nums.clone();
        
        // Frequency count of how many times we can set each index to zero directly
        int[] canSetZero = new int[n];
        
        // For each second, update the capabilities
        for (int i = 0; i < m; i++) {
            int index = changeIndices[i];
            canSetZero[index]++;
            
            // If at second i+1 we can set the value to 0, calculate when it's possible to mark this index
            if (decrementsNeeded[index] <= canSetZero[index]) {
                earliestZero[index] = Math.min(earliestZero[index], i + 1);
            }
        }
        
        // Check the possibility of marking all indices
        int latestSecond = 0;
        for (int i = 0; i < n; i++) {
            if (earliestZero[i] == Integer.MAX_VALUE) {
                return -1;
            }
            latestSecond = Math.max(latestSecond, earliestZero[i]);
        }
        
        return latestSecond;
    }
}
