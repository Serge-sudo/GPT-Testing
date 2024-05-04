#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int maxLen = 0;
    int start = 0;
    int lastSeen[256]; // Assuming ASCII character set
    memset(lastSeen, -1, sizeof(lastSeen));
    
    for (int i = 0; i < n; i++) {
        if (lastSeen[(unsigned char)s[i]] >= start) {
            start = lastSeen[(unsigned char)s[i]] + 1;
        }
        lastSeen[(unsigned char)s[i]] = i;
        maxLen = (i - start + 1 > maxLen) ? i - start + 1 : maxLen;
    }
    
    return maxLen;
}
