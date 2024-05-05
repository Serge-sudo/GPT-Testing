public class Solution {
    public long findMaximumNumber(long k, int x) {
        long accumulatedPrice = 0;
        long num = 0;

        while (true) {
            num++;
            long price = 0;
            for (int i = 1; (i - 1) * x < 64; i++) { // Considering up to 64 bits
                if ((num & (1L << ((i - 1) * x))) != 0) {
                    price++;
                }
            }

            accumulatedPrice += price;

            if (accumulatedPrice > k) {
                return num - 1;
            }
        }
    }
}
