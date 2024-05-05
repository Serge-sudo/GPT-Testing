#include <string.h>
#include <stdlib.h>
#include <limits.h>

int maxPartitionsAfterOperations(char* s, int k) {
    int n = strlen(s);
    int result = 0;
    
    // Function to count partitions with an option to change one character at pos to char newChar
    int count_partitions_with_change(int pos, char newChar) {
        int freq[26] = {0};
        int count = 0, distinct = 0, partitions = 0;
        int i = 0, j = 0;

        for (; j < n; ++j) {
            // Simulate the change at position `pos`
            char currentChar = (j == pos) ? newChar : s[j];

            if (freq[currentChar - 'a'] == 0) distinct++;
            freq[currentChar - 'a']++;
            
            // While distinct characters exceed k, shrink the window from the left
            while (distinct > k) {
                freq[s[i] - 'a']--;
                if (freq[s[i] - 'a'] == 0) distinct--;
                i++;
            }

            // Increment count when reaching the change or end of the string
            if (j == pos || j == n - 1) {
                partitions++;
                // Reset for next possible partition sequence
                memset(freq, 0, sizeof(freq));
                distinct = 0;
                i = j + 1;
            }
        }

        return partitions;
    }

    // First, calculate partitions without any change
    result = count_partitions_with_change(-1, 'a'); // -1 means no change

    // Try changing each character to any other lowercase character to maximize partitions
    for (int i = 0; i < n; ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            if (s[i] != c) { // Only consider a change
                result = max(result, count_partitions_with_change(i, c));
            }
        }
    }

    return result;
}
