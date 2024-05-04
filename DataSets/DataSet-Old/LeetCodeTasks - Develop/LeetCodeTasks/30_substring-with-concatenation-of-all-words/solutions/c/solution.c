#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Helper function to check if the current segment is a valid permutation
int is_valid_permutation(char *segment, char **words, int word_count, int word_len) {
    int segment_len = word_count * word_len;
    int *found = (int *)calloc(word_count, sizeof(int));  // Array to track found words
    int valid = 1;

    for (int i = 0; i < segment_len; i += word_len) {
        char temp[word_len + 1];
        strncpy(temp, segment + i, word_len);
        temp[word_len] = '\0';

        int matched = 0;
        for (int j = 0; j < word_count; j++) {
            if (found[j] == 0 && strncmp(words[j], temp, word_len) == 0) {
                found[j] = 1;
                matched = 1;
                break;
            }
        }

        if (!matched) {
            valid = 0;
            break;
        }
    }

    free(found);
    return valid;
}

// Function to find all starting indices of concatenated substrings in 's'
int* findSubstring(char *s, char **words, int wordsSize, int *returnSize) {
    int word_len = strlen(words[0]);
    int total_len = wordsSize * word_len;
    int s_len = strlen(s);
    int *result = (int *)malloc(s_len * sizeof(int));
    int count = 0;

    for (int i = 0; i <= s_len - total_len; i++) {
        char *segment = s + i;
        if (is_valid_permutation(segment, words, wordsSize, word_len)) {
            result[count++] = i;
        }
    }

    *returnSize = count;
    return result;
}

