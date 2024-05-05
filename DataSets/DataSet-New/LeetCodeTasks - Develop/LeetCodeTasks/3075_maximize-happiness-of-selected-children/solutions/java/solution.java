import java.util.PriorityQueue;

class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        for (int value : happiness) {
            maxHeap.add(value);
        }
        
        long maxHappinessSum = 0;
        for (int i = 0; i < k; i++) {
            int selected = maxHeap.poll();
            maxHappinessSum += selected;
            if (selected > 1) {
                maxHeap.add(selected - 1);
            }
        }
        
        return maxHappinessSum;
    }
}
