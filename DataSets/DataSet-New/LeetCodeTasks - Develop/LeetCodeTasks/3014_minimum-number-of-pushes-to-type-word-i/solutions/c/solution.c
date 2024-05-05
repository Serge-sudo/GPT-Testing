#include <string.h>
#include <limits.h>

int minimumPushes(char* word) {
    int n = strlen(word);
    int minPushes = INT_MAX;

    // Iterate over all possible mappings of distinct letters to the keys 2 to 9
    // There are 8 keys and we have to distribute n letters among these keys
    for (int i = 0; i < (1 << (3 * n)); i++) {
        int count[8] = {0};
        int valid = 1;
        int pushes = 0;

        // Assign each letter to a key (from 2 to 9, mapping to 0-7)
        for (int j = 0; j < n; j++) {
            int key = (i >> (3 * j)) & 7;  // 3 bits per letter, hence 3*j shift
            if (key > 7) {
                valid = 0;
                break;
            }
            count[key]++;
        }

        // Check if the mapping is valid (no more than one key is unassigned)
        int usedKeys = 0;
        for (int j = 0; j < 8; j++) {
            if (count[j] > 0)
                usedKeys++;
        }
        if (usedKeys < (n + 1) / 2) valid = 0; // Ensure enough keys are used

        // Calculate the number of pushes for this mapping if valid
        if (valid) {
            for (int j = 0; j < 8; j++) {
                // If 2 letters are assigned to the same key, first costs 1 push, second costs 2 pushes, etc.
                for (int k = 1; k <= count[j]; k++) {
                    pushes += k;
                }
            }
            // Update minimum pushes
            if (pushes < minPushes) {
                minPushes = pushes;
            }
        }
    }

    return minPushes;
}
