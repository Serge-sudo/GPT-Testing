#include <stdio.h>

long long countAlternatingSubarrays(int* nums, int numsSize) {
    long long total = 0;
    int length = 1;
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            length++;
        } else {
            total += (long long)length * (length + 1) / 2;
            length = 1;
        }
    }
    
    total += (long long)length * (length + 1) / 2;
    
    return total;
}
