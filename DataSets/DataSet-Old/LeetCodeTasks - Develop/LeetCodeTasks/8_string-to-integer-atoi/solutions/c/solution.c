#include <limits.h>
#include <ctype.h>

int myAtoi(char *s) {
    long result = 0; // To store the resultant number
    int sign = 1;    // To handle the sign of the number

    // Step 1: Skip the leading whitespaces
    while (*s == ' ') {
        s++;
    }

    // Step 2: Check for the sign indicator
    if (*s == '-' || *s == '+') {
        sign = (*s == '-') ? -1 : 1;
        s++;
    }

    // Step 3: Convert the number and stop if a non-digit character is encountered
    while (isdigit(*s)) {
        result = result * 10 + (*s - '0');
        s++;
        
        // Step 5: Handle overflow cases
        if (result * sign > INT_MAX) return INT_MAX;
        if (result * sign < INT_MIN) return INT_MIN;
    }

    // Step 6: Apply the sign and return the result
    return (int)(result * sign);
}
