#include <stdbool.h>

int countKeyChanges(char* s) {
    int changes = 0;
    bool isUpperCase = false;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            if (!isUpperCase) {
                isUpperCase = true;
                changes++;
            }
        } else {
            if (isUpperCase) {
                isUpperCase = false;
                changes++;
            }
        }
    }

    return changes;
}
