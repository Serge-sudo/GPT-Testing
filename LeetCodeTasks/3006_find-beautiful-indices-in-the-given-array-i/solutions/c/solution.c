#include <string.h>
#include <stdlib.h>

int* beautifulIndices(char* s, char* a, char* b, int k, int* returnSize) {
    int s_len = strlen(s);
    int a_len = strlen(a);
    int b_len = strlen(b);
    int *beautiful = (int *)malloc(s_len * sizeof(int)); // Allocate enough space
    int count = 0;

    // Check indices for string a
    for (int i = 0; i <= s_len - a_len; i++) {
        if (strncmp(s + i, a, a_len) == 0) {
            // Now look for b in range [i - k, i + k]
            int start = i - k < 0 ? 0 : i - k;
            int end = i + k > s_len - b_len ? s_len - b_len : i + k;
            int found = 0;
            for (int j = start; j <= end; j++) {
                if (strncmp(s + j, b, b_len) == 0) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                beautiful[count++] = i;
            }
        }
    }

    *returnSize = count;
    beautiful = (int *)realloc(beautiful, count * sizeof(int)); // Reallocate to fit the exact number of beautiful indices
    return beautiful;
}
