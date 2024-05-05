import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

class Solution {
    public int maximumSetSize(int[] nums1, int[] nums2) {
        Map<Integer, Integer> freq1 = new HashMap<>();
        Map<Integer, Integer> freq2 = new HashMap<>();
        
        // Populate frequency maps
        for (int num : nums1) {
            freq1.put(num, freq1.getOrDefault(num, 0) + 1);
        }
        for (int num : nums2) {
            freq2.put(num, freq2.getOrDefault(num, 0) + 1);
        }
        
        // Priority queue to process the most frequent elements first
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((a, b) -> b[1] - a[1]);
        for (Map.Entry<Integer, Integer> entry : freq1.entrySet()) {
            maxHeap.offer(new int[] {entry.getKey(), entry.getValue()});
        }
        for (Map.Entry<Integer, Integer> entry : freq2.entrySet()) {
            maxHeap.offer(new int[] {entry.getKey(), entry.getValue()});
        }
        
        Map<Integer, Integer> finalFreqs = new HashMap<>();
        int n = nums1.length;
        int targetSize = n / 2;
        
        // Try to fit as many unique numbers as possible
        while (!maxHeap.isEmpty() && targetSize > 0) {
            int[] entry = maxHeap.poll();
            int num = entry[0];
            int count = entry[1];
            
            if (finalFreqs.containsKey(num)) {
                int existingCount = finalFreqs.get(num);
                int total = existingCount + count;
                if (total > n / 2) {
                    finalFreqs.put(num, n / 2);
                } else {
                    finalFreqs.put(num, total);
                }
            } else {
                finalFreqs.put(num, Math.min(count, targetSize));
            }
            
            targetSize -= Math.min(count, targetSize);
        }
        
        return finalFreqs.size();
    }
}
