#include <stdlib.h>
#include <string.h>

char* getSmallestString(char* s, int k) {
    int n = strlen(s);
    char* t = (char*)malloc((n + 1) * sizeof(char));
    strcpy(t, s);  // Copy s into t to start with the original string
    t[n] = '\0';   // Ensure t is null-terminated

    for (int i = 0; i < n && k > 0; ++i) {
        // Calculate the current character's position and the target character 'a'
        int current_char = s[i] - 'a';
        int target_char = 0;  // We want to move towards 'a'

        // Calculate minimum cyclic distance to 'a'
        int dist = current_char >= target_char ? current_char - target_char : 26 - (target_char - current_char);
        
        // If 'a' is further than 'z' direction because of cycle, reconsider the distance
        int alt_dist = 26 - dist;  // Opposite direction
        int min_dist = dist < alt_dist ? dist : alt_dist;

        if (min_dist <= k) {
            t[i] = 'a';   // Change the current character to 'a'
            k -= min_dist; // Reduce the available k by the distance used
        }
    }

    return t;
}
