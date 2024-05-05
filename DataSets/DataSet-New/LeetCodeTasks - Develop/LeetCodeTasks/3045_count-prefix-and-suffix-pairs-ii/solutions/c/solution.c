#include <stdbool.h>
#include <string.h>

bool isPrefixAndSuffix(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 > len2) {
        return false;
    }
    // Check if str1 is a prefix of str2
    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    // Check if str1 is a suffix of str2
    for (int i = 0; i < len1; i++) {
        if (str1[len1 - 1 - i] != str2[len2 - 1 - i]) {
            return false;
        }
    }
    return true;
}

long long countPrefixSuffixPairs(char** words, int wordsSize) {
    long long count = 0;
    for (int i = 0; i < wordsSize - 1; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            if (isPrefixAndSuffix(words[i], words[j])) {
                count++;
            }
        }
    }
    return count;
}
