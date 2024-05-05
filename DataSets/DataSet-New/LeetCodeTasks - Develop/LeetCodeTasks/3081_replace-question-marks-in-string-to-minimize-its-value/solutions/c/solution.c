#include <string.h>

char* minimizeStringValue(char* s) {
    int freq[26] = {0}; // to keep track of frequency of letters in the string
    int len = strlen(s);
    
    // First pass: count existing letters
    for (int i = 0; i < len; ++i) {
        if (s[i] != '?') {
            freq[s[i] - 'a']++;
        }
    }
    
    // Second pass: replace '?' with lexicographically smallest possible letter that minimizes the value
    for (int i = 0; i < len; ++i) {
        if (s[i] == '?') {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (freq[c - 'a'] == 0) { // choose the smallest unused character
                    s[i] = c;
                    freq[c - 'a']++; // update frequency
                    break;
                }
            }
        }
    }
    
    return s;
}
