import java.util.PriorityQueue;

class Solution {
    public int minOperations(int[] nums, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int num : nums) {
            minHeap.add(num);
        }
        
        int operations = 0;
        while (minHeap.peek() < k) {
            int smallest = minHeap.poll();
            int secondSmallest = minHeap.poll();
            
            int newElement = smallest * 2 + secondSmallest;
            minHeap.add(newElement);
            operations++;
        }
        
        return operations;
    }
}
