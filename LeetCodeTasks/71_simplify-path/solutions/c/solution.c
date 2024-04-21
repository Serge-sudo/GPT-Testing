#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* simplifyPath(char* path) {
    int path_len = strlen(path);
    char* stack = (char*)malloc(path_len + 1);
    int top = 0;  // Top of the stack (acts as the size of the stack)

    // Tokenize input path by '/'
    char* token = strtok(path, "/");
    while (token != NULL) {
        if (strcmp(token, "..") == 0) {
            // Go up one level unless at root
            if (top > 0) {
                // Move back to previous '/'
                while (top > 0 && stack[--top] != '/');
                // Remove trailing '/'
                if (top > 0) top--;
            }
        } else if (strcmp(token, ".") != 0) {
            // Normal directory name (not '.' or '..')
            stack[top++] = '/';
            memcpy(stack + top, token, strlen(token));
            top += strlen(token);
        }
        token = strtok(NULL, "/");
    }

    // Special case: if the stack is empty, return root
    if (top == 0) return strcpy(stack, "/");

    // Null terminate the stack content
    stack[top] = '\0';
    return stack;
}
