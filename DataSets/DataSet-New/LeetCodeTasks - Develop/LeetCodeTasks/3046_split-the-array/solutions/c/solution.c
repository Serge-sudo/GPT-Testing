#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isPossibleToSplit(int* nums, int numsSize) {
    int freq[101] = {0};  // Frequency array for numbers between 1 and 100
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }

    int maxFreq = 0;  // Find the maximum frequency
    for (int i = 1; i <= 100; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }
    
    // Check if we can divide the numbers into two parts with distinct elements
    return maxFreq <= numsSize / 2;
}
