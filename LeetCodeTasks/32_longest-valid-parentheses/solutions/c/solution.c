#include <string.h>

int longestValidParentheses(char* s) {
    int max_len = 0;
    int left = 0, right = 0;
    int n = strlen(s);
    
    // Left to right scan
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            max_len = max_len > 2 * right ? max_len : 2 * right;
        } else if (right > left) {
            left = right = 0;
        }
    }
    
    left = right = 0;
    // Right to left scan
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            max_len = max_len > 2 * left ? max_len : 2 * left;
        } else if (left > right) {
            left = right = 0;
        }
    }
    
    return max_len;
}
