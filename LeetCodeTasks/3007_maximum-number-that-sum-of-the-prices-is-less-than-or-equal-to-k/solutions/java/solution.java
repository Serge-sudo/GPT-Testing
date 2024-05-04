public class Solution {
    public long findMaximumNumber(long k, int x) {
        long accumulatedPrice = 0;
        long num = 0;
        
        while (true) {
            num++;
            long price = 0;
            for (int i = x - 1; i < 64; i += x) {
                if ((num & (1L << i)) != 0) {
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
