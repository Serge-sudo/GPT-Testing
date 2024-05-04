#include <stdbool.h>
#include <string.h>

bool isMatch(char* s, char* p) {
    if (*p == '\0') return *s == '\0';

    bool first_match = (*s != '\0' && (*p == *s || *p == '.'));

    if (strlen(p) >= 2 && p[1] == '*') {
        return (isMatch(s, p + 2) || (first_match && isMatch(s + 1, p)));
    } else {
        return first_match && isMatch(s + 1, p + 1);
    }
}
