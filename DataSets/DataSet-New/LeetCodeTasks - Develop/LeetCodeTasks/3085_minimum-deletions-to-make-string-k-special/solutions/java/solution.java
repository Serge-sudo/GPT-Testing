import java.util.HashMap;
import java.util.ArrayList;
import java.util.Collections;

class Solution {
    public int minimumDeletions(String word, int k) {
        HashMap<Character, Integer> freqMap = new HashMap<>();
        for (char ch : word.toCharArray()) {
            freqMap.put(ch, freqMap.getOrDefault(ch, 0) + 1);
        }
        
        ArrayList<Integer> frequencies = new ArrayList<>(freqMap.values());
        Collections.sort(frequencies);
        
        int totalChars = word.length();
        int minDeletions = Integer.MAX_VALUE;
        int n = frequencies.size();
        
        // Prefix sum to help calculate sum of frequencies efficiently
        int[] prefixSum = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + frequencies.get(i - 1);
        }
        
        // Trying different frequency target from minimum to maximum frequency available
        for (int i = 0; i < n; i++) {
            int targetFreq = frequencies.get(i);
            int lo = 0, hi = i;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (targetFreq - frequencies.get(mid) > k) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
            
            int deleteBelow = prefixSum[i] - prefixSum[lo];
            int deleteAbove = 0;
            if (i + 1 < n) {
                deleteAbove = (prefixSum[n] - prefixSum[i + 1]) - (n - i - 1) * targetFreq;
            }
            
            int currentDeletion = deleteBelow + deleteAbove;
            minDeletions = Math.min(minDeletions, currentDeletion);
        }
        
        return minDeletions;
    }
}
