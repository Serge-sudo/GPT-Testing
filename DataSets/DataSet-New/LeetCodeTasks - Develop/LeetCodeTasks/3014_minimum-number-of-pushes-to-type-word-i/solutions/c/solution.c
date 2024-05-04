#include <stdio.h>
#include <stdlib.h>

int minimumPushes(char* word) {
    int pushes[26] = {0};
    int mapping[26] = {0};

    for (int i = 0; word[i] != '\0'; i++) {
        pushes[word[i] - 'a']++;
    }

    int current_push = 1;
    for (int i = 0; i < 26; i++) {
        if (pushes[i] > 0) {
            mapping[i] = current_push;
            current_push++;
        }
    }

    int total_pushes = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        total_pushes += mapping[word[i] - 'a'];
    }

    return total_pushes;
}
