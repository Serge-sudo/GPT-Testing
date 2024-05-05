#include <string.h>

int strStr(char* haystack, char* needle) {
    int needleLen = strlen(needle);
    int haystackLen = strlen(haystack);
    
    // If needle is an empty string, return 0 (first occurrence is at index 0)
    if (needleLen == 0) return 0;

    for (int i = 0; i <= haystackLen - needleLen; i++) {
        // Check substring starting at index `i`
        if (strncmp(haystack + i, needle, needleLen) == 0) {
            return i;
        }
    }
    
    return -1;
}
