#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int lengthA = strlen(a);
    int lengthB = strlen(b);
    int maxLen = (lengthA > lengthB) ? lengthA : lengthB;
    char* result = (char*) malloc(maxLen + 2); // Extra space for carry and null terminator
    result[maxLen + 1] = '\0'; // Null terminator

    int carry = 0;
    int i = lengthA - 1, j = lengthB - 1, k = maxLen;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result[k--] = (sum % 2) + '0'; // Convert sum result to char '0' or '1'
        carry = sum / 2;
    }

    if (result[0] == '\0') { // If the first character is not set
        memmove(result, result + 1, maxLen + 1); // Shift everything left by one
    }

    return result;
}
