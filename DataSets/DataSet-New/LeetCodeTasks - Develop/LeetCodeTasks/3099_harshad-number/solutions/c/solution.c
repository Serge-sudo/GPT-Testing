#include <stdio.h>

int sumOfTheDigitsOfHarshadNumber(int x) {
    int original = x;
    int sumOfDigits = 0;
    while (x > 0) {
        sumOfDigits += x % 10;
        x /= 10;
    }
    if (original % sumOfDigits == 0) {
        return sumOfDigits;
    } else {
        return -1;
    }
}
