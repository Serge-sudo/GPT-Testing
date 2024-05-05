#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int maximumLength(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    
    int maxLen = 0;
    for (int i = 0; i < numsSize;) {
        int current = nums[i];
        int count = 0;
        while (i < numsSize && nums[i] == current) {
            count++;
            i++;
        }
        
        int p = 1;
        while (p < count) {
            p *= 2;
        }
        if (p > count) p /= 2;
        
        int len = 2 * p - 1;
        if (len > maxLen) {
            maxLen = len;
        }
    }
    
    return maxLen;
}
