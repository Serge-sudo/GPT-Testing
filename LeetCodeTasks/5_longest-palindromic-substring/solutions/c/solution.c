#include <string.h>

char* longestPalindrome(char* s) {
    int n = strlen(s);
    int start = 0, maxLen = 1;
    
    // A function to check if the substring from low to high is palindrome
    void expandAroundCenter(int low, int high) {
        while (low >= 0 && high < n && s[low] == s[high]) {
            if (high - low + 1 > maxLen) {
                maxLen = high - low + 1;
                start = low;
            }
            low--;
            high++;
        }
    }
    
    // Check for all possible centers for palindromes
    for (int i = 0; i < n; i++) {
        expandAroundCenter(i, i);      // Odd length palindromes
        expandAroundCenter(i, i + 1);  // Even length palindromes
    }
    
    s[start + maxLen] = '\0'; // Null-terminate the palindromic substring
    return s + start;
}
