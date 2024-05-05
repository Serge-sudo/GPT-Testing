#include <stdbool.h>

long long findMaximumNumber(long long k, int x) {
    long long accumulatedPrice = 0;
    long long num = 0;

    while (true) {
        num++;
        long long price = 0;
        for (long long i = x - 1; i < 64; i += x) {
            if ((num & (1LL << i)) != 0) {
                price++;
            }
        }

        accumulatedPrice += price;
        if (accumulatedPrice > k) {
            return num - 1;
        }
    }
}
