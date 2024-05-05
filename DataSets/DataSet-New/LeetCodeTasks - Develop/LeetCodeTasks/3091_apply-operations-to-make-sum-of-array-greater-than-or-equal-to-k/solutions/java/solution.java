class Solution {
    public int minOperations(int k) {
        if (k == 1) return 0;

        int sum = 1;
        int ops = 0;
        int maxElement = 1;

        while (sum < k) {
            if (sum + maxElement <= k) {
                sum += maxElement;
                ops++; // This operation was a duplication
            } else {
                int needed = k - sum;
                maxElement += needed;
                sum += needed;
                ops += needed; // These operations are increment operations
                break;
            }
        }

        return ops;
    }
}
