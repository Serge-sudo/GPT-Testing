#include <limits.h>

int minimumSubarrayLength(int* nums, int numsSize, int k) {
    if (numsSize == 0) return -1;
    
    int min_length = INT_MAX;
    int j = 0, current_or = 0;
    
    for (int i = 0; i < numsSize; i++) {
        while (j < numsSize && current_or < k) {
            current_or |= nums[j];
            j++;
        }
        if (current_or >= k) {
            min_length = (min_length > (j - i)) ? (j - i) : min_length;
        }
        current_or ^= nums[i];
    }
    
    return min_length == INT_MAX ? -1 : min_length;
}
