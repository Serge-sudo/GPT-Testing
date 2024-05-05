#include <string.h>
#include <stdlib.h>

int minimumPushes(char* word) {
    int freq[26] = {0};
    int len = strlen(word);

    // Calculate frequency of each letter
    for (int i = 0; i < len; i++) {
        freq[word[i] - 'a']++;
    }

    // Sort frequencies in descending order
    qsort(freq, 26, sizeof(int), (int (*)(const void*, const void*)) strcmp);

    int pushes = 0;
    int k = 1; // Key presses for the position on the key

    // Distribute the most frequent letters to the least number of key presses
    for (int i = 25; i >= 0 && freq[i] > 0; i--) {
        pushes += freq[i] * k;
        if (i % 3 == 0) k++; // Every three characters, increment the key presses needed
    }

    return pushes;
}
