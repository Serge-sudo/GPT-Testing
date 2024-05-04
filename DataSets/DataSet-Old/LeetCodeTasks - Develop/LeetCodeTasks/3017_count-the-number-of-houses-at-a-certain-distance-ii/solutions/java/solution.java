import java.util.Arrays;

class Solution {
    public long[] countOfPairs(int n, int x, int y) {
        long[] result = new long[n];
        int dist = Math.min(Math.abs(x - y), n - Math.abs(x - y));
        for (int k = 1; k <= dist; k++) {
            result[k - 1] += 2L * k * (dist - k + 1);
        }
        return result;
    }
}
