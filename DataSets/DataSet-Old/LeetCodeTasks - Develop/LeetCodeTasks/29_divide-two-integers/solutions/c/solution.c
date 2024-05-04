#include <limits.h>

int divide(int dividend, int divisor) {
    // Special case for overflow
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    
    // Determine the signs
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    
    // Use long to handle extreme cases like INT_MIN
    long long ldividend = labs(dividend);
    long long ldivisor = labs(divisor);
    
    long long result = 0;
    
    // Perform division using bit manipulation and subtraction
    while (ldividend >= ldivisor) {
        long long temp = ldivisor, multiple = 1;
        while (ldividend >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        ldividend -= temp;
        result += multiple;
    }
    
    // Apply the sign
    return sign == 1 ? result : -result;
}
