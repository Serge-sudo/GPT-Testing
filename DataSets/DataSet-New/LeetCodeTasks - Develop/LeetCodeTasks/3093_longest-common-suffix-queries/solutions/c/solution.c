#include <stdlib.h>
#include <string.h>

int* stringIndices(char** wordsContainer, int wordsContainerSize, char** wordsQuery, int wordsQuerySize, int* returnSize) {
    *returnSize = wordsQuerySize;
    int* result = malloc(sizeof(int) * wordsQuerySize);
    if (!result) return NULL;

    for (int i = 0; i < wordsQuerySize; i++) {
        int maxSuffixLength = 0;
        int minLength = 0x7FFFFFFF; // Large initial value for minimum length
        int bestIndex = -1;
        
        for (int j = 0; j < wordsContainerSize; j++) {
            int queryLen = strlen(wordsQuery[i]);
            int containerLen = strlen(wordsContainer[j]);
            int suffixLen = 0;
            
            // Calculate the length of the longest common suffix
            while (suffixLen < queryLen && suffixLen < containerLen &&
                   wordsQuery[i][queryLen - 1 - suffixLen] == wordsContainer[j][containerLen - 1 - suffixLen]) {
                suffixLen++;
            }
            
            // Determine the best match based on the conditions
            if (suffixLen > maxSuffixLength || 
                (suffixLen == maxSuffixLength && containerLen < minLength) ||
                (suffixLen == maxSuffixLength && containerLen == minLength && bestIndex == -1)) {
                maxSuffixLength = suffixLen;
                minLength = containerLen;
                bestIndex = j;
            }
        }
        
        result[i] = bestIndex;
    }
    
    return result;
}
