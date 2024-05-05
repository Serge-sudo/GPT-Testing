import java.util.PriorityQueue;

class Solution {
    public long findKthSmallest(int[] coins, int k) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for (int coin : coins) {
            pq.add((long) coin);
        }
        
        long current = 0;
        while (k > 0) {
            current = pq.poll();
            k--;
            for (int coin : coins) {
                long next = current + coin;
                // Avoid duplicates and overflow
                if (next > current && !pq.contains(next)) {
                    pq.add(next);
                }
            }
        }
        return current;
    }
}
