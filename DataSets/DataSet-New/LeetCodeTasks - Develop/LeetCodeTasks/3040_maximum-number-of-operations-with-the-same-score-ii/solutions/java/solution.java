import java.util.HashMap;

public class Solution {
    public int maxOperations(int[] nums) {
        int n = nums.length;
        HashMap<Integer, Integer> freqMap = new HashMap<>();

        // Calculate possible pairs and their frequencies
        for (int i = 0; i < n / 2; i++) {
            int pair1 = nums[i] + nums[i + 1]; // First two elements
            freqMap.put(pair1, freqMap.getOrDefault(pair1, 0) + 1);
            int pair2 = nums[n - 1 - i] + nums[n - 2 - i]; // Last two elements
            freqMap.put(pair2, freqMap.getOrDefault(pair2, 0) + 1);
            if (i != n - 1 - i) {
                int pair3 = nums[i] + nums[n - 1 - i]; // First and last elements
                freqMap.put(pair3, freqMap.getOrDefault(pair3, 0) + 1);
            }
        }

        // If the array has an odd length, the middle pair is not counted in the loop
        if (n % 2 == 1) {
            int mid = n / 2;
            int pair1 = nums[mid] + nums[mid - 1];
            freqMap.put(pair1, freqMap.getOrDefault(pair1, 0) + 1);
            int pair2 = nums[mid] + nums[mid + 1];
            freqMap.put(pair2, freqMap.getOrDefault(pair2, 0) + 1);
        }

        // Get the maximum frequency among all pairs
        int maxOperations = 0;
        for (int freq : freqMap.values()) {
            maxOperations = Math.max(maxOperations, freq);
        }

        return maxOperations;
    }
}
