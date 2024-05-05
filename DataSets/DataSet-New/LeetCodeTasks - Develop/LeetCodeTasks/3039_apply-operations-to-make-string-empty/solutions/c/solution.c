#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char* lastNonEmptyString(char* s) {
    int n = strlen(s);
    char* result = malloc(n + 1);  // Allocate memory for the result
    if (!result) return NULL;  // Check for allocation failure
    strcpy(result, s);  // Copy the original string into result

    int count[26] = {0};  // To store the count of each character 'a' to 'z'
    for (int i = 0; i < n; ++i) {
        count[s[i] - 'a']++;
    }

    bool changed;
    do {
        changed = false;  // This flag checks if any character was removed
        for (int i = 0; i < 26; ++i) {
            if (count[i] > 0) {  // There's at least one character to remove
                for (int j = 0; j < n; ++j) {
                    if (result[j] == 'a' + i) {  // Match found
                        result[j] = '\0';  // Remove character by setting it to null
                        count[i]--;
                        changed = true;
                        break;
                    }
                }
            }
        }
        // Compress the string to remove null characters
        int k = 0;
        for (int j = 0; j < n; ++j) {
            if (result[j] != '\0') {
                result[k++] = result[j];
            }
        }
        result[k] = '\0';  // Null terminate the compressed string
        n = k;  // Update the length of the string
    } while (changed && n > 0);  // Continue until no changes are made or string is empty

    return result;  // Return the result, which is the last non-empty state
}
