class Solution {
    public long[] countOfPairs(int n, int x, int y) {
        // Ensure x is less than y for easier calculation
        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }

        long[] result = new long[n];

        // Calculate minimum distances using the added shortcut between x and y
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int directDist = j - i;
                int viaXYDist = Math.abs(i - x) + 1 + Math.abs(y - j); // 1 for the edge between x and y
                int minDist = Math.min(directDist, viaXYDist);
                
                if (minDist < n) {
                    result[minDist]++;
                }
            }
        }

        // Each pair (i, j) is bidirectional, so multiply the count by 2
        for (int k = 1; k < n; k++) {
            result[k] *= 2;
        }

        return result;
    }
}
