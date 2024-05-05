#include <ctype.h>
#include <string.h>

int numberOfSpecialChars(char* word) {
    int count[26] = {0};
    int specialCount = 0;

    for (int i = 0; word[i] != '\0'; i++) {
        if (islower(word[i])) {
            count[word[i] - 'a'] |= 1;  // Mark the lowercase occurrence
        } else {
            count[word[i] - 'A'] |= 2;  // Mark the uppercase occurrence
        }
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] == 3) {  // Check if both lowercase and uppercase were marked
            specialCount++;
        }
    }

    return specialCount;
}
