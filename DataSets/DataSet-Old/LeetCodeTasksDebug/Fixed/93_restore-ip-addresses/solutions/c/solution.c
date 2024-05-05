#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** restoreIpAddresses(char* s, int* returnSize) {
    int n = strlen(s);
    char** result = (char**)malloc(100 * sizeof(char*));
    *returnSize = 0;
    char ip[16];  // IP address cannot be longer than 15 characters

    // Function to extract a substring from a string
    char* strndup(const char* s, size_t n) {
        char* p = (char*)malloc(n + 1);
        strncpy(p, s, n);
        p[n] = '\0';
        return p;
    }

    for (int a = 1; a <= 3; a++)
        for (int b = 1; b <= 3; b++)
            for (int c = 1; c <= 3; c++)
                for (int d = 1; d <= 3; d++)
                    if (a + b + c + d == n) {
                        char* sa = strndup(s, a);
                        char* sb = strndup(s + a, b);
                        char* sc = strndup(s + a + b, c);
                        char* sd = strndup(s + a + b + c, d);

                        int A = atoi(sa);
                        int B = atoi(sb);
                        int C = atoi(sc);
                        int D = atoi(sd);

                        free(sa);
                        free(sb);
                        free(sc);
                        free(sd);

                        // Ensure no leading zeros unless it's a single zero
                        if ((a > 1 && s[0] == '0') || (b > 1 && s[a] == '0') || (c > 1 && s[a + b] == '0') || (d > 1 && s[a + b + c] == '0')) {
                            continue;
                        }

                        if (A <= 255 && B <= 255 && C <= 255 && D <= 255) {
                            snprintf(ip, sizeof(ip), "%d.%d.%d.%d", A, B, C, D);
                            result[*returnSize] = strdup(ip);
                            (*returnSize)++;
                        }
                    }

    return result;
}
