#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* countAndSay(int n) {
    if (n == 1) return strdup("1");

    char* previous = countAndSay(n - 1);
    int length = strlen(previous);
    int count = 1;
    char* result = malloc(length * 2 + 1); // Allocating max possible space needed
    int resultIndex = 0;

    for (int i = 1; i <= length; i++) {
        if (i < length && previous[i] == previous[i - 1]) {
            count++;
        } else {
            int addedLength = sprintf(result + resultIndex, "%d%c", count, previous[i - 1]);
            resultIndex += addedLength;
            count = 1;
        }
    }

    free(previous);
    return result;
}
