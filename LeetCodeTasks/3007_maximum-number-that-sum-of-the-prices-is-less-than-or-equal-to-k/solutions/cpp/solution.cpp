#include <vector>
#include <iostream>

class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        long long num = 1;
        long long accumulatedPrice = 0;

        while (true) {
            long long currentPrice = 0;
            for (long long i = x - 1; (i < 64); i += x) {
                if (num & (1LL << i)) {
                    currentPrice++;
                }
            }
            if (accumulatedPrice + currentPrice > k) {
                break;
            }
            accumulatedPrice += currentPrice;
            num++;
        }

        return num - 1;
    }
};
