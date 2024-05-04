#include <stdio.h>

// Function to calculate the price of a number based on set bits at positions x, 2x, 3x, ...
long long calculatePrice(long long num, int x) {
    long long price = 0;
    for (int i = x - 1; num > (1LL << i); i += x) {
        if ((num & (1LL << i)) != 0) {
            price++;
        }
    }
    return price;
}

// Function to find the greatest cheap number
long long findMaximumNumber(long long k, int x) {
    long long accumulatedPrice = 0;
    long long num = 0;

    while (true) {
        long long price = calculatePrice(num + 1, x);
        if (accumulatedPrice + price > k) {
            break;
        }
        num++;
        accumulatedPrice += price;
    }

    return num;
}
