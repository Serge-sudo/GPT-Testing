#include <stdio.h>
#include <stdlib.h>

int minimumPushes(char* word) {
    int pushes = 0;
    while (*word != '\0') {
        char current = *word;
        if (current >= 'a' && current <= 'o') {
            pushes += (current - 'a') % 3 + 1;
        } else if (current >= 'p' && current <= 's') {
            pushes += (current - 'p') % 4 + 1;
        } else if (current >= 't' && current <= 'v') {
            pushes += (current - 't') % 3 + 1;
        } else if (current >= 'w' && current <= 'z') {
            pushes += (current - 'w') % 4 + 1;
        }
        word++;
    }
    return pushes;
}
