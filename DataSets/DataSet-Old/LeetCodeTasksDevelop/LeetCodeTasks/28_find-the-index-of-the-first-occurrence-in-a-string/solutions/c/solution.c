#include <string.h>

int strStr(char* haystack, char* needle) {
    int needleLen = strlen(needle);
    int haystackLen = strlen(haystack);
    
    if (needleLen == 0) return 0;

    for (int i = 0; i <= haystackLen - needleLen; i++) {
        if (strncmp(haystack + i, needle, needleLen) == 0) {
            return i;
        }
    }
    
    return -1;
}
