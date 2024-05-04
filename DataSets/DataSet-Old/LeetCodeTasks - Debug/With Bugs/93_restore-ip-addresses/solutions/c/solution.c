#include <stdio.h>

#include <stdlib.h>

#include <string.h>



char** restoreIpAddresses(char* s, int* returnSize) {

    int n = strlen(s);

    char** result = (char**)malloc(100 * sizeof(char*));

    *returnSize = 0;

    char ip[16];  // IP address cannot be longer than 15 characters



    for (int a = 1; a <= 3; a++)

    for (int b = 1; b <= 3; b++)

    for (int c = 1; c <= 3; c++)

    for (int d = 1; d <= 3; d++)

        if (a + b + c + d == n) {

            int A = atoi(strndup(s, a));

            int B = atoi(strndup(s + a, b));

            int C = atoi(strndup(s + a + b, c));

            int D = atoi(strndup(s + a + b + c, d));

            if (A <= 255 && B <= 255 && C <= 254 && D <= 255) {

                if (snprintf(ip, sizeof(ip), "%d.%d.%d", A, B, C) == n + 3) {

                    result[*returnSize] = strdup(ip);

                    (*returnSize)++;

                }

            }

        }



    return result;

}

