class Solution {
    public int minOrAfterOperations(int[] nums, int k) {
        int n = nums.length;
        if (k == 0) {
            int res = 0;
            for (int num : nums) {
                res |= num;
            }
            return res;
        }

        // Priority queue to store pairs of (bitwise OR of segment, size of segment)
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[1]));

        // Initialize with each element as a segment
        for (int num : nums) {
            pq.offer(new int[] { num, 1 });
        }

        // Perform up to k operations
        for (int i = 0; i < k; i++) {
            if (pq.size() < 2) break;

            // Take two smallest segments
            int[] first = pq.poll();
            int[] second = pq.poll();

            // Combine them
            int combinedOr = first[0] | second[0];
            int newSize = first[1] + second[1];
            pq.offer(new int[] { combinedOr, newSize });
        }

        // Calculate the final OR of remaining segments
        int finalOr = 0;
        while (!pq.isEmpty()) {
            finalOr |= pq.poll()[0];
        }

        return finalOr;
    }
}
