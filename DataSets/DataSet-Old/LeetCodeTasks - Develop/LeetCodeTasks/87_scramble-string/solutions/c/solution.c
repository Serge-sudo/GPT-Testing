#include <stdbool.h>
#include <string.h>

bool isScrambleHelper(char *s1, char *s2, int l1, int l2, int length, int ***memo) {
    if (memo[l1][l2][length] != -1) {
        return memo[l1][l2][length];
    }
    
    // Compare the substrings directly
    if (strncmp(s1 + l1, s2 + l2, length) == 0) {
        memo[l1][l2][length] = 1;
        return true;
    }
    
    // Count characters
    int count[26] = {0};
    for (int i = 0; i < length; i++) {
        count[s1[l1 + i] - 'a']++;
        count[s2[l2 + i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            memo[l1][l2][length] = 0;
            return false;
        }
    }

    // Try every possible split
    for (int i = 1; i < length; i++) {
        // Case 1: No swap
        if (isScrambleHelper(s1, s2, l1, l2, i, memo) && isScrambleHelper(s1, s2, l1 + i, l2 + i, length - i, memo)) {
            memo[l1][l2][length] = 1;
            return true;
        }
        // Case 2: Swap
        if (isScrambleHelper(s1, s2, l1, l2 + length - i, i, memo) && isScrambleHelper(s1, s2, l1 + i, l2, length - i, memo)) {
            memo[l1][l2][length] = 1;
            return true;
        }
    }

    memo[l1][l2][length] = 0;
    return false;
}

bool isScramble(char* s1, char* s2) {
    int n = strlen(s1);
    int ***memo = malloc(n * sizeof(int **));
    for (int i = 0; i < n; i++) {
        memo[i] = malloc(n * sizeof(int *));
        for (int j = 0; j < n; j++) {
            memo[i][j] = malloc((n + 1) * sizeof(int));
            for (int k = 0; k <= n; k++) {
                memo[i][j][k] = -1;
            }
        }
    }
    
    bool result = isScrambleHelper(s1, s2, 0, 0, n, memo);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            free(memo[i][j]);
        }
        free(memo[i]);
    }
    free(memo);
    
    return result;
}
