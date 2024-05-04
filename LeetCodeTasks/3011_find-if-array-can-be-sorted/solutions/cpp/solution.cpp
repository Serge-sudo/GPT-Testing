#include <stdbool.h>
#include <stdlib.h>

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int compare(const void* a, const void* b) {
    int countA = countSetBits(*(const int*)a);
    int countB = countSetBits(*(const int*)b);
    if (countA == countB) {
        return *(const int*)a - *(const int*)b;
    } else {
        return countA - countB;
    }
}

bool canSortArray(int* nums, int numsSize) {
    int* sorted = (int*)malloc(numsSize * sizeof(int));
    if (!sorted) return false;
    
    for (int i = 0; i < numsSize; ++i) {
        sorted[i] = nums[i];
    }
    
    qsort(sorted, numsSize, sizeof(int), compare);
    
    for (int i = 0; i < numsSize; ++i) {
        if (countSetBits(sorted[i]) != countSetBits(nums[i])) {
            free(sorted);
            return false;
        }
    }
    
    free(sorted);
    return true;
}
