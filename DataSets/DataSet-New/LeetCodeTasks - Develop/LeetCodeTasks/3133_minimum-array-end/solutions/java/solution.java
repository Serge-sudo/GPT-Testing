class Solution {
    public long minEnd(int n, int x) {
        long end = x;
        for (int i = 1; i < n; i++) {
            end += 1L << Integer.numberOfTrailingZeros(x);
        }
        return end;
    }
}
