#include <stdio.h>

int longestMonotonicSubarray(int* nums, int numsSize) {
    if (numsSize == 1) {
        return 1;
    }
    
    int max_length = 1;
    int current_length = 1;
    int i;

    // Check for strictly increasing sequences
    for (i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            current_length++;
            if (current_length > max_length) {
                max_length = current_length;
            }
        } else {
            current_length = 1;
        }
    }
    
    // Check for strictly decreasing sequences
    current_length = 1; // reset for new direction check
    for (i = 1; i < numsSize; i++) {
        if (nums[i] < nums[i - 1]) {
            current_length++;
            if (current_length > max_length) {
                max_length = current_length;
            }
        } else {
            current_length = 1;
        }
    }

    return max_length;
}
