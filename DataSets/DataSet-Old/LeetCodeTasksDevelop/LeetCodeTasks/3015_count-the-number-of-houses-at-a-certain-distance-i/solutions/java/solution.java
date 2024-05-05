import java.util.*;

class Solution {
    public int[] countOfPairs(int n, int x, int y) {
        int[] result = new int[n];
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (Math.abs(i - j) == k || (Math.abs(i - x) + Math.abs(j - y) + 1) == k || (Math.abs(i - y) + Math.abs(j - x) + 1) == k) {
                        result[k - 1]++;
                    }
                }
            }
        }
        return result;
    }
}
