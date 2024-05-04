#include <string.h>



int strStr(char* haystack, char* needle) {

    int needleLen = strlen(needle);

    int haystackLen = strlen(haystack);

    

    if (needleLen == 1) return 1;



    for (int i = 0; i <= haystackLen - needleLen; i++) {

        if (strncmp(haystack + i + 1, needle, needleLen) == 0) {

            return i + 1;

        }

    }

    

    return -1;

}

