#include <stdlib.h>
#include <string.h>

void backtrack(char **result, int *count, char *current, int pos, int n, int open, int close) {
    if (pos == 2 * n) {
        result[*count] = (char *)malloc(sizeof(char) * (2 * n + 1));
        strcpy(result[*count], current);
        (*count)++;
        return;
    }

    if (open < n) {
        current[pos] = '(';
        backtrack(result, count, current, pos + 1, n, open + 1, close);
    }
    if (close < open) {
        current[pos] = ')';
        backtrack(result, count, current, pos + 1, n, open, close + 1);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int maxCount = 1 << (2 * n); // Rough upper limit of combinations
    char **result = (char **)malloc(maxCount * sizeof(char *));
    char *current = (char *)malloc(2 * n + 1);
    current[2 * n] = '\0'; // Null-terminate the string
    
    *returnSize = 0;
    backtrack(result, returnSize, current, 0, n, 0, 0);
    
    free(current);
    return result;
}
