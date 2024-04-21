#include <stdlib.h>
#include <string.h>

int cmpfunc(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    // Map to track sorted strings and their group indices
    char** keys = malloc(strsSize * sizeof(char*));
    int* indices = malloc(strsSize * sizeof(int));
    int numGroups = 0;

    // Temp array to store sorted strings
    for (int i = 0; i < strsSize; i++) {
        keys[i] = strdup(strs[i]);
        qsort(keys[i], strlen(keys[i]), sizeof(char), cmpfunc);
    }

    // Grouping by sorted string
    for (int i = 0; i < strsSize; i++) {
        int j = 0;
        for (; j < numGroups; j++) {
            if (strcmp(keys[indices[j]], keys[i]) == 0) {
                break;
            }
        }
        if (j == numGroups) {
            indices[numGroups++] = i;
        }
    }

    // Allocating result array
    char*** result = malloc(numGroups * sizeof(char**));
    *returnColumnSizes = malloc(numGroups * sizeof(int));
    *returnSize = numGroups;

    // Fill in the result array
    for (int i = 0; i < numGroups; i++) {
        result[i] = malloc(strsSize * sizeof(char*));
        int count = 0;
        for (int j = 0; j < strsSize; j++) {
            if (strcmp(keys[indices[i]], keys[j]) == 0) {
                result[i][count++] = strs[j];
            }
        }
        (*returnColumnSizes)[i] = count;
        result[i] = realloc(result[i], count * sizeof(char*)); // Trim excess memory
    }

    // Cleanup
    for (int i = 0; i < strsSize; i++) {
        free(keys[i]);
    }
    free(keys);
    free(indices);

    return result;
}
