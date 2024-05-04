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
    int countA = countSetBits(*(int*)a);
    int countB = countSetBits(*(int*)b);
    if (countA == countB) {
        return *(int*)a - *(int*)b;
    } else {
        return countA - countB;
    }
}

bool canSortArray(int* nums, int numsSize) {
    int* sorted = (int*)malloc(numsSize * sizeof(int));
    if (!sorted) return false;
    for (int i = 0; i < numsSize; i++) {
        sorted[i] = nums[i];
    }
    qsort(sorted, numsSize, sizeof(int), compare);
    int* binCountSorted = (int*)malloc(numsSize * sizeof(int));
    if (!binCountSorted) {
        free(sorted);
        return false;
    }
    for (int i = 0; i < numsSize; i++) {
        binCountSorted[i] = countSetBits(sorted[i]);
    }
    for (int i = 1; i < numsSize; i++) {
        if (binCountSorted[i] == binCountSorted[i - 1]) continue;
        int j = 0;
        while (j < numsSize && countSetBits(nums[j]) != binCountSorted[i - 1]) {
            j++;
        }
        int k = j;
        while (k < numsSize && countSetBits(nums[k]) == binCountSorted[i - 1]) {
            k++;
        }
        if (k == numsSize || countSetBits(nums[k]) != binCountSorted[i]) {
            free(sorted);
            free(binCountSorted);
            return false;
        }
    }
    free(sorted);
    free(binCountSorted);
    return true;
}
