#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* beautifulIndices(char* s, char* a, char* b, int k, int* returnSize) {
    int len_s = strlen(s), len_a = strlen(a), len_b = strlen(b);
    int maxA = len_s - len_a;
    int maxB = len_s - len_b;
    int *result = (int*) malloc(sizeof(int) * (len_s + 1)); // Allocate max possible size
    *returnSize = 0;

    // First, find all indices where substring a appears in s
    bool *indices_a = (bool*) calloc(len_s, sizeof(bool));
    for (int i = 0; i <= maxA; i++) {
        if (strncmp(s + i, a, len_a) == 0) {
            indices_a[i] = true;
        }
    }

    // Second, find all indices where substring b appears in s
    bool *indices_b = (bool*) calloc(len_s, sizeof(bool));
    for (int j = 0; j <= maxB; j++) {
        if (strncmp(s + j, b, len_b) == 0) {
            indices_b[j] = true;
        }
    }

    // Check for beautiful indices
    for (int i = 0; i <= maxA; i++) {
        if (indices_a[i]) {
            for (int j = 0; j <= maxB; j++) {
                if (indices_b[j] && abs(j - i) <= k) {
                    result[(*returnSize)++] = i;
                    break;
                }
            }
        }
    }

    free(indices_a);
    free(indices_b);

    return result;
}
