#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int n = strlen(s);
    char stack[n];
    int top = -1;
    
    for (int i = 0; i < n; i++) {
        char c = s[i];
        switch (c) {
            case '(': 
            case '{': 
            case '[':
                stack[++top] = c;
                break;
            case ')': 
                if (top == -1 || stack[top] != '(') return false;
                top--;
                break;
            case '}': 
                if (top == -1 || stack[top] != '{') return false;
                top--;
                break;
            case ']': 
                if (top == -1 || stack[top] != '[') return false;
                top--;
                break;
        }
    }
    return top == -1;
}
