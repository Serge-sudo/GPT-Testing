#include <stdbool.h>
#include <string.h>

int maxPalindromesAfterOperations(char** words, int wordsSize) {
    int charCount[26] = {0};
    
    // Count frequency of each character across all words
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; words[i][j]; j++) {
            charCount[words[i][j] - 'a']++;
        }
    }
    
    int totalPairs = 0;
    int oddCount = 0;
    
    // Calculate total pairs and count of odd characters
    for (int i = 0; i < 26; i++) {
        totalPairs += charCount[i] / 2;
        if (charCount[i] % 2 == 1) {
            oddCount++;
        }
    }
    
    // Determine maximum number of palindromes
    int maxPalindromes = totalPairs / (wordsSize / 2);
    if (wordsSize % 2 == 1) maxPalindromes++;
    
    return (maxPalindromes > wordsSize) ? wordsSize : maxPalindromes;
}
