#include <string.h>
#include <stdlib.h>
#include <limits.h>

int maxPartitionsAfterOperations(char* s, int k) {
    int n = strlen(s);
    int max_partitions = 1;
    char original_char;
    
    // Helper function to count partitions with at most k distinct characters
    int count_partitions(char* str) {
        int partitions = 0;
        int l = 0, distinct = 0, freq[26] = {0};
        
        for (int r = 0; r < n; r++) {
            if (freq[str[r] - 'a']++ == 0) distinct++;
            while (distinct > k) {
                if (--freq[str[l] - 'a'] == 0) distinct--;
                l++;
            }
            partitions++;
        }
        
        return partitions;
    }
    
    // First, evaluate the partition count without any changes
    max_partitions = count_partitions(s);
    
    // Check changing each character if it potentially improves the partition count
    for (int i = 0; i < n; i++) {
        original_char = s[i];
        for (char c = 'a'; c <= 'z'; c++) {
            if (c != original_char) {
                s[i] = c;
                int partitions = count_partitions(s);
                if (partitions > max_partitions) {
                    max_partitions = partitions;
                }
            }
        }
        s[i] = original_char; // Restore original character
    }
    
    return max_partitions;
}
