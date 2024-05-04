#include <string.h>
#include <stdlib.h>

int* beautifulIndices(char* s, char* a, char* b, int k, int* returnSize) {
    int sLen = strlen(s);
    int aLen = strlen(a);
    int bLen = strlen(b);
    int* result = (int*) malloc(sizeof(int) * sLen);
    int resultCount = 0;
    
    // To store indices where substrings a and b start
    int* indicesOfA = (int*) malloc(sizeof(int) * sLen);
    int* indicesOfB = (int*) malloc(sizeof(int) * sLen);
    int countA = 0, countB = 0;
    
    // Finding all indices where a and b occur in s
    for (int i = 0; i <= sLen - aLen; i++) {
        if (strncmp(s + i, a, aLen) == 0) {
            indicesOfA[countA++] = i;
        }
    }
    for (int i = 0; i <= sLen - bLen; i++) {
        if (strncmp(s + i, b, bLen) == 0) {
            indicesOfB[countB++] = i;
        }
    }
    
    // Check each index of a if it can be considered beautiful
    for (int i = 0; i < countA; i++) {
        int indexA = indicesOfA[i];
        bool beautiful = false;
        for (int j = 0; j < countB && !beautiful; j++) {
            int indexB = indicesOfB[j];
            if (abs(indexB - indexA) <= k) {
                beautiful = true;
                result[resultCount++] = indexA;
            }
        }
    }
    
    free(indicesOfA);
    free(indicesOfB);
    
    *returnSize = resultCount;
    return result;
}
