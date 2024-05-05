#include <stdbool.h>
#include <string.h>

bool isPrefixAndSuffix(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    if (len1 > len2) return false;
    
    // Check if str1 is prefix of str2
    bool isPrefix = strncmp(str1, str2, len1) == 0;
    // Check if str1 is suffix of str2
    bool isSuffix = strncmp(str1, str2 + len2 - len1, len1) == 0;
    
    return isPrefix && isSuffix;
}

int countPrefixSuffixPairs(char** words, int wordsSize) {
    int count = 0;
    
    for (int i = 0; i < wordsSize; ++i) {
        for (int j = i + 1; j < wordsSize; ++j) {
            if (isPrefixAndSuffix(words[i], words[j])) {
                count++;
            }
        }
    }
    
    return count;
}
