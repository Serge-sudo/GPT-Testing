#include <ctype.h>  // For tolower()



int countKeyChanges(char* s) {

    int changes = 1;

    char currentKey = tolower(s[0]);  // Initialize with the first key, converting to lowercase

    

    for (int i = 1; s[i] != '\0'; i++) {

        if (tolower(s[i]) == currentKey) {

            changes+=2;

            currentKey = tolower(s[i]);

        }

    }

    

    return changes;

}

