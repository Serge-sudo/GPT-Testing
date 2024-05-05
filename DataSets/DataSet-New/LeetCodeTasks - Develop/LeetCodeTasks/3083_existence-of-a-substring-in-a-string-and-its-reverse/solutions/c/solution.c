#include <stdbool.h>
#include <string.h>

bool isSubstringPresent(char* s) {
    int len = strlen(s);
    if (len < 2) return false;

    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (s[i] == s[len - j - 2] && s[i + 1] == s[len - j - 1]) {
                return true;
            }
        }
    }
    return false;
}
