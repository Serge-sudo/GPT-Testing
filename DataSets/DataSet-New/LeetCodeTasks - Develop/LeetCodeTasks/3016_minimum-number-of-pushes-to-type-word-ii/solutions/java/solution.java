import java.util.HashMap;
import java.util.PriorityQueue;

class Solution {
    public int minimumPushes(String word) {
        // Frequency map for characters in the word
        HashMap<Character, Integer> freq = new HashMap<>();
        for (char ch : word.toCharArray()) {
            freq.put(ch, freq.getOrDefault(ch, 0) + 1);
        }

        // Max-heap based on frequency of characters
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        maxHeap.addAll(freq.values());

        int pushes = 0;
        while (!maxHeap.isEmpty()) {
            // Take the top up to 9 most frequent letters (since we have keys 2-9, i.e., 8 keys)
            int[] topFrequencies = new int[9]; // Track top frequencies in current round
            int size = Math.min(9, maxHeap.size());
            for (int i = 0; i < size; i++) {
                topFrequencies[i] = maxHeap.poll();
            }

            // Compute the pushes and decrease frequencies accordingly
            for (int i = 0; i < size; i++) {
                pushes += (i + 1) * topFrequencies[i];
            }
        }

        return pushes;
    }
}
