#include <limits.h>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handling overflow cases
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // Determining signs of the result
        bool negative = (dividend < 0) != (divisor < 0);

        // Use long to handle overflow from -INT_MIN
        long long ldividend = labs(dividend);
        long long ldivisor = labs(divisor);

        long long result = 0;
        long long count;
        while (ldividend >= ldivisor) {
            long long temp = ldivisor;
            count = 1;
            // Exponential search
            while (temp <= ldividend - temp) {
                temp += temp;
                count += count;
            }
            ldividend -= temp;
            result += count;
        }

        // Apply the sign to the result
        if (negative) result = -result;
        
        // Final type casting to int, as problem constraints ensure fit within int range
        return (int)result;
    }
};
