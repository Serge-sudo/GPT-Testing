#include <stdlib.h>

long long* mostFrequentIDs(int* nums, int numsSize, int* freq, int freqSize, int* returnSize) {
    // The map for counting occurrences of each ID
    long long *idCounts = calloc(100001, sizeof(long long));
    long long mostFreqCount = 0;
    long long *ans = malloc(numsSize * sizeof(long long));
    *returnSize = numsSize;
    
    for (int i = 0; i < numsSize; i++) {
        int id = nums[i];
        int change = freq[i];
        
        if (change > 0) {
            // Adding IDs to the collection
            idCounts[id] += change;
            if (idCounts[id] > mostFreqCount) {
                mostFreqCount = idCounts[id];
            }
        } else if (change < 0) {
            // Removing IDs from the collection
            idCounts[id] += change;
            if (idCounts[id] == mostFreqCount) {
                // Need to check if this was the last ID of the most frequent count
                mostFreqCount = 0; // Reset and find new max
                for (int j = 1; j <= 100000; j++) {
                    if (idCounts[j] > mostFreqCount) {
                        mostFreqCount = idCounts[j];
                    }
                }
            }
        }
        
        ans[i] = mostFreqCount; // Store the count of the most frequent ID after each step
    }
    
    free(idCounts);
    return ans;
}
