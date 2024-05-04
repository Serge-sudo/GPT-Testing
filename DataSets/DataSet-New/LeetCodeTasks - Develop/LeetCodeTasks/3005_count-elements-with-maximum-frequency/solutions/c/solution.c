#include <stdio.h>

int maxFrequencyElements(int* nums, int numsSize) {
    int count[101] = {0};
    int maxFreq = 0;
    
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
        if (count[nums[i]] > maxFreq) {
            maxFreq = count[nums[i]];
        }
    }
    
    int result = 0;
    for (int i = 1; i <= 100; i++) {
        if (count[i] == maxFreq) {
            result += count[i];
        }
    }
    
    return result;
}
