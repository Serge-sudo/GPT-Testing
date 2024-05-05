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

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

bool canSortArray(int* nums, int numsSize) {
    // Create an array to store the number of set bits for each element in nums
    int setBits[numsSize];
    for (int i = 0; i < numsSize; i++) {
        setBits[i] = countSetBits(nums[i]);
    }

    // Create a copy of setBits and sort it to check the desired order
    int sortedSetBits[numsSize];
    for (int i = 0; i < numsSize; i++) {
        sortedSetBits[i] = setBits[i];
    }
    qsort(sortedSetBits, numsSize, sizeof(int), compare);

    // Check if it's possible to sort setBits to match sortedSetBits using adjacent swaps
    for (int i = 0; i < numsSize; i++) {
        // Find the next matching setBits count in the unsorted portion
        int j = i;
        while (j < numsSize && setBits[j] != sortedSetBits[i])
            j++;

        // If we didn't find a match, sorting is not possible
        if (j == numsSize) return false;

        // Bubble the found element back to position i
        while (j > i) {
            // Swap elements in setBits
            int temp = setBits[j];
            setBits[j] = setBits[j - 1];
            setBits[j - 1] = temp;
            j--;
        }
    }

    return true;
}
