#include <string.h>
#include <ctype.h>

int numberOfSpecialChars(char* word) {
    int firstUpper[26];
    int lastLower[26];
    memset(firstUpper, -1, sizeof(firstUpper));
    memset(lastLower, -1, sizeof(lastLower));
    
    int i = 0;
    while (word[i] != '\0') {
        char ch = word[i];
        if (islower(ch)) {
            int index = ch - 'a';
            if (lastLower[index] == -1) {
                lastLower[index] = i;
            }
            lastLower[index] = i;
        } else if (isupper(ch)) {
            int index = ch - 'A';
            if (firstUpper[index] == -1) {
                firstUpper[index] = i;
            }
        }
        i++;
    }
    
    int specialCount = 0;
    for (int j = 0; j < 26; j++) {
        if (lastLower[j] != -1 && firstUpper[j] != -1 && lastLower[j] < firstUpper[j]) {
            specialCount++;
        }
    }
    
    return specialCount;
}
