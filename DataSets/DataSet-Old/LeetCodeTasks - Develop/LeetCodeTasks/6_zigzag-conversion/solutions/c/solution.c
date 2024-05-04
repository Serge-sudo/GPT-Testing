#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows == 1 || numRows >= strlen(s)) return strdup(s);

    char *result = malloc(strlen(s) + 1);
    int cursor = 0, len = strlen(s);

    for (int r = 0; r < numRows; r++) {
        int increment = 2 * (numRows - 1);
        for (int i = r; i < len; i += increment) {
            result[cursor++] = s[i];
            if (r > 0 && r < numRows - 1 && i + increment - 2 * r < len)
                result[cursor++] = s[i + increment - 2 * r];
        }
    }
    result[cursor] = '\0';
    return result;
}
