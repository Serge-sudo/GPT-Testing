#include <stdio.h>
#include <stdlib.h>

char* getPermutation(int n, int k) {
    char *result = (char *)malloc((n + 1) * sizeof(char));
    int factorial[n + 1];
    factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorial[i] = factorial[i - 1] * i;
    }

    k--; // Convert k from 1-based index to 0-based index for easier calculation.
    char available[10];
    for (int i = 0; i < n; i++) {
        available[i] = '1' + i; // Initialize the list of available characters.
    }

    for (int i = 0; i < n; i++) {
        int idx = k / factorial[n - 1 - i];
        result[i] = available[idx];
        // Remove used character by shifting the rest
        for (int j = idx; j < n - 1; j++) {
            available[j] = available[j + 1];
        }
        k %= factorial[n - 1 - i];
    }

    result[n] = '\0'; // Null-terminate the string.
    return result;
}
