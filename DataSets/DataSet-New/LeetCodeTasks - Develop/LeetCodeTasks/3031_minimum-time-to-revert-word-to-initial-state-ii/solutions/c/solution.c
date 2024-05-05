#include <string.h>

int minimumTimeToInitialState(char* word, int k) {
    int n = strlen(word);
    if (n % k != 0) return n / k + 1;
    return n / k;
}
