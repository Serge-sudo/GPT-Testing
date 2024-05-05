#include <limits.h>

int minimumSubarrayLength(int* nums, int numsSize, int k) {
    int minLength = INT_MAX;
    
    for (int i = 0; i < numsSize; ++i) {
        int currentOR = 0;
        for (int j = i; j < numsSize; ++j) {
            currentOR |= nums[j];
            if (currentOR >= k) {
                minLength = (j - i + 1 < minLength) ? j - i + 1 : minLength;
                break;
            }
        }
    }
    
    return (minLength == INT_MAX) ? -1 : minLength;
}
