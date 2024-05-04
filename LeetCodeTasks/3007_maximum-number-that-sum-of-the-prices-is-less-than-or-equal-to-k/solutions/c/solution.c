#include <stdio.h>

// Function to count the set bits in an integer
int countSetBits(long long n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

// Function to calculate the price of a number based on the given rules
int calculatePrice(long long num, int x) {
    int price = 0;
    for (int i = x; i <= 63; i += x) {
        if ((num & (1LL << (i - 1))) != 0)
            price++;
    }
    return price;
}

// Main function to find the greatest cheap number
long long findMaximumNumber(long long k, int x) {
    long long accumulatedPrice = 0;
    long long num = 1;

    // Continue until the accumulated price exceeds k
    while (true) {
        int price = calculatePrice(num, x);
        accumulatedPrice += price;
        if (accumulatedPrice > k) {
            break;
        }
        num++;
    }
    
    // The last number where the condition was satisfied
    return num - 1;
}
