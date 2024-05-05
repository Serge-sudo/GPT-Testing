#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int* beautifulIndices(char* s, char* a, char* b, int k, int* returnSize) {
    int sLen = strlen(s);
    int aLen = strlen(a);
    int bLen = strlen(b);
    int *result = (int*)malloc(sizeof(int) * sLen); // Allocate maximum possible size
    int count = 0;

    // Precompute all indices where substring a and b occur
    int *aIndices = (int*)malloc(sizeof(int) * sLen);
    int *bIndices = (int*)malloc(sizeof(int) * sLen);
    int aCount = 0, bCount = 0;
    
    for (int i = 0; i <= sLen - aLen; i++) {
        if (strncmp(s + i, a, aLen) == 0) {
            aIndices[aCount++] = i;
        }
    }
    
    for (int i = 0; i <= sLen - bLen; i++) {
        if (strncmp(s + i, b, bLen) == 0) {
            bIndices[bCount++] = i;
        }
    }

    // Check each aIndex if there's a bIndex within range k
    for (int i = 0; i < aCount; i++) {
        int ai = aIndices[i];
        bool isBeautiful = false;
        for (int j = 0; j < bCount; j++) {
            int bj = bIndices[j];
            if (abs(bj - ai) <= k) {
                isBeautiful = true;
                break;
            }
        }
        if (isBeautiful) {
            result[count++] = ai;
        }
    }

    // Cleanup
    free(aIndices);
    free(bIndices);

    // Set the size of the output array
    *returnSize = count;
    return result;
}
