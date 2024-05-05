#include <stdlib.h>

int compareInt(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int medianOfUniquenessArray(int* nums, int numsSize) {
    int* counts = (int*)calloc(numsSize + 1, sizeof(int));
    int* uniqCounts = (int*)calloc(numsSize * (numsSize + 1) / 2, sizeof(int));
    int index = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int* seen = (int*)calloc(100001, sizeof(int));
        int distinctCount = 0;
        for (int j = i; j < numsSize; j++) {
            if (seen[nums[j]] == 0) {
                distinctCount++;
            }
            seen[nums[j]]++;
            uniqCounts[index++] = distinctCount;
        }
        free(seen);
    }
    
    qsort(uniqCounts, index, sizeof(int), compareInt);
    
    int result = uniqCounts[(index - 1) / 2];
    
    free(counts);
    free(uniqCounts);
    
    return result;
}
