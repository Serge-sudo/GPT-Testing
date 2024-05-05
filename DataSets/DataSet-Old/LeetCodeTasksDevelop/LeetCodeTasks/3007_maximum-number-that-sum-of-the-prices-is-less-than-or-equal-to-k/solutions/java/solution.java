public class Solution {
    public long findMaximumNumber(long k, int x) {
        long accumulatedPrice = 0;
        long num = 0;

        while (true) {
            num++;
            long price = 0;
            long currentNum = num;
            int position = 1;

            while (currentNum > 0) {
                if (position % x == 0) {
                    if ((currentNum & 1) == 1) {
                        price++;
                    }
                }
                currentNum >>= 1;
                position++;
            }

            accumulatedPrice += price;

            if (accumulatedPrice > k) {
                return num - 1;
            }
        }
    }
}
