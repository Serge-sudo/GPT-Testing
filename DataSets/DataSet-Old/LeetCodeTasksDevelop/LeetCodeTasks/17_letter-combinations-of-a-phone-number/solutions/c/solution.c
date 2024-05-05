#include <stdlib.h>
#include <string.h>

char** letterCombinations(char* digits, int* returnSize) {
    char* phoneMap[10] = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    
    int length = strlen(digits);
    if (length == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    // Calculate total number of combinations
    int totalCombinations = 1;
    for (int i = 0; i < length; i++) {
        totalCombinations *= strlen(phoneMap[digits[i] - '0']);
    }
    
    char** result = (char**)malloc(totalCombinations * sizeof(char*));
    for (int i = 0; i < totalCombinations; i++) {
        result[i] = (char*)malloc((length + 1) * sizeof(char));
        result[i][length] = '\0';
    }
    
    int repeatFactor = totalCombinations;
    for (int i = 0; i < length; i++) {
        char* currentChars = phoneMap[digits[i] - '0'];
        int currentCharsLen = strlen(currentChars);
        repeatFactor /= currentCharsLen;
        int k = 0;
        while (k < totalCombinations) {
            for (int m = 0; m < currentCharsLen; m++) {
                for (int n = 0; n < repeatFactor; n++) {
                    result[k][i] = currentChars[m];
                    k++;
                }
            }
        }
    }
    
    *returnSize = totalCombinations;
    return result;
}
