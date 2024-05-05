#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char** shortestSubstrings(char** arr, int arrSize, int* returnSize) {
    *returnSize = arrSize;
    char **answer = (char **)malloc(sizeof(char *) * arrSize);
    
    for (int i = 0; i < arrSize; i++) {
        int len = strlen(arr[i]);
        answer[i] = (char *)malloc(sizeof(char));
        answer[i][0] = '\0'; // Start with an empty string
        
        // To find the shortest unique substring
        bool found = false;
        for (int l = 1; l <= len && !found; l++) { // length of substrings
            char **substrings = (char **)malloc(sizeof(char *) * (len - l + 1));
            for (int j = 0; j <= len - l; j++) {
                substrings[j] = (char *)malloc(sizeof(char) * (l + 1));
                strncpy(substrings[j], arr[i] + j, l);
                substrings[j][l] = '\0';
            }

            // Sort the substrings to find the lexicographically smallest easily
            for (int m = 0; m < len - l; m++) {
                for (int n = m + 1; n < len - l + 1; n++) {
                    if (strcmp(substrings[m], substrings[n]) > 0) {
                        char *temp = substrings[m];
                        substrings[m] = substrings[n];
                        substrings[n] = temp;
                    }
                }
            }

            // Check each substring against all other strings
            for (int j = 0; j <= len - l && !found; j++) {
                bool unique = true;
                for (int k = 0; k < arrSize && unique; k++) {
                    if (i != k && strstr(arr[k], substrings[j]) != NULL) {
                        unique = false;
                    }
                }
                if (unique) {
                    found = true;
                    free(answer[i]); // Free previous empty string
                    answer[i] = (char *)malloc(sizeof(char) * (l + 1));
                    strcpy(answer[i], substrings[j]);
                }
            }

            // Free allocated substrings
            for (int j = 0; j <= len - l; j++) {
                free(substrings[j]);
            }
            free(substrings);
        }
    }
    
    return answer;
}
