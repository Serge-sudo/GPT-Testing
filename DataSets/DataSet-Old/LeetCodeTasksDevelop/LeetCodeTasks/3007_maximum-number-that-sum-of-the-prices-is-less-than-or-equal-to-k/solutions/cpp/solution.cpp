#include <cmath>
#include <iostream>

class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        long long left = 1, right = k;
        while (left < right) {
            long long mid = (left + right + 1) / 2;
            if (calculateAccumulatedPrice(mid, x) <= k)
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
    
private:
    int calculatePrice(long long num, int x) {
        int count = 0;
        while (num > 0) {
            if (num % 2 == 1) count++;
            num /= 2;
        }
        return count;
    }
    
    long long calculateAccumulatedPrice(long long num, int x) {
        long long accumulatedPrice = 0, factor = 1;
        while (num > 0) {
            accumulatedPrice += calculatePrice(num, x) * factor;
            factor *= 2;
            num /= 2;
        }
        return accumulatedPrice;
    }
};
