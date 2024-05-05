import java.util.Arrays;

class Solution {
    public String getSmallestString(String s, int k) {
        char[] t = s.toCharArray();
        int n = t.length;

        for (int i = 0; i < n; i++) {
            if (k <= 0) {
                break;
            }
            char current = t[i];
            // Find the minimum possible character we can change to while adjusting the distance
            char bestChar = 'a';
            int bestDistance = Math.min(Math.abs(current - 'a'), 26 - Math.abs(current - 'a'));

            if (bestDistance <= k) {
                t[i] = bestChar;
                k -= bestDistance;
            }
        }

        return new String(t);
    }
}
