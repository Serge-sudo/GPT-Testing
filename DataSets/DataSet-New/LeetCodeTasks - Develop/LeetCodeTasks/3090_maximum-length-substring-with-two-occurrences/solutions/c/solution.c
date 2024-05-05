#include <string.h>

int maximumLengthSubstring(char* s) {
    int maxLen = 0;
    int start = 0;
    int freq[256] = {0};  // Frequency of characters in the current window
    int n = strlen(s);

    for (int end = 0; end < n; end++) {
        freq[s[end]]++;

        // Check and reduce the window size until no character count exceeds 2
        while (freq[s[end]] > 2) {
            freq[s[start]]--;
            start++;
        }

        // Update maximum length of valid substring found
        maxLen = (end - start + 1 > maxLen) ? (end - start + 1) : maxLen;
    }

    return maxLen;
}
