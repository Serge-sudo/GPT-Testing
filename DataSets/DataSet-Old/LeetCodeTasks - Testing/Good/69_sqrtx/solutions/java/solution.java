class Solution {
    public int mySqrt(int x) {
        if (x == 0) return 0;
        long left = 1, right = x, mid, sq;
        while (left <= right) {
            mid = left + (right - left) / 2;
            sq = mid * mid;
            if (sq == x) return (int) mid;
            else if (sq < x) left = mid + 1;
            else right = mid - 1;
        }
        return (int) right;
    }
}
