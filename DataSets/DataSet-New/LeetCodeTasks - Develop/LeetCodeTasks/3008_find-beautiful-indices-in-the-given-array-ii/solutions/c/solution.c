#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* beautifulIndices(char* s, char* a, char* b, int k, int* returnSize) {
    int lenS = strlen(s);
    int lenA = strlen(a);
    int lenB = strlen(b);
    int* result = malloc(sizeof(int) * lenS); // Maximum possible number of indices is lenS
    int count = 0;

    // Search indices for strings a and b in s
    int* indicesA = malloc(sizeof(int) * lenS);
    int countA = 0;
    for (int i = 0; i <= lenS - lenA; i++) {
        if (strncmp(s + i, a, lenA) == 0) {
            indicesA[countA++] = i;
        }
    }

    int* indicesB = malloc(sizeof(int) * lenS);
    int countB = 0;
    for (int i = 0; i <= lenS - lenB; i++) {
        if (strncmp(s + i, b, lenB) == 0) {
            indicesB[countB++] = i;
        }
    }

    // Check for each index of a if there exists an index of b within distance k
    for (int i = 0; i < countA; i++) {
        int idxA = indicesA[i];
        bool found = false;
        for (int j = 0; j < countB && !found; j++) {
            int idxB = indicesB[j];
            if (abs(idxB - idxA) <= k) {
                found = true;
                result[count++] = idxA;
            }
        }
    }

    free(indicesA);
    free(indicesB);

    *returnSize = count;
    return result;
}
