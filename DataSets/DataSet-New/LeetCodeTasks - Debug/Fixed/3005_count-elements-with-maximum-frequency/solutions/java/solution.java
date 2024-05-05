import java.util.HashMap;

class Solution {

    public int maxFrequencyElements(int[] nums) {
        HashMap<Integer, Integer> freqMap = new HashMap<>();
        int maxFreq = 0;

        // Count the frequency of each number
        for (int num : nums) {
            int count = freqMap.getOrDefault(num, 0) + 1;
            freqMap.put(num, count);
            maxFreq = Math.max(maxFreq, count);  // Update the maximum frequency found
        }

        int maxFreqCount = 0;

        // Calculate the total count of numbers with the maximum frequency
        for (int key : freqMap.keySet()) {
            if (freqMap.get(key) == maxFreq) {
                maxFreqCount += maxFreq;
            }
        }

        return maxFreqCount;
    }
}
