import java.util.Arrays;

class Solution {
    public int minimumArrayLength(int[] nums) {
        int gcdResult = nums[0];
        for (int num : nums) {
            gcdResult = gcd(gcdResult, num);
            if (gcdResult == 1) {
                return 1; // If at any point GCD is 1, the array can be reduced to size 1.
            }
        }
        return gcdResult == 1 ? 1 : nums.length; // If GCD is not 1, minimal reduction is not possible.
    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
