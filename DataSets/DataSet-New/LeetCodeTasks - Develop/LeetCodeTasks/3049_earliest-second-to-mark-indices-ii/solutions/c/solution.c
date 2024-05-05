#include <limits.h>
#include <stdbool.h>

int earliestSecondToMarkIndices(int* nums, int numsSize, int* changeIndices, int changeIndicesSize) {
    // `to_zero` will keep track of the earliest second we can set each index to zero
    int to_zero[numsSize];
    for (int i = 0; i < numsSize; i++) {
        to_zero[i] = INT_MAX;
    }

    // Track when each index can potentially be zeroed out
    for (int s = 0; s < changeIndicesSize; s++) {
        int index = changeIndices[s] - 1; // converting 1-based to 0-based index
        if (to_zero[index] == INT_MAX) {
            to_zero[index] = s + 1; // We can set this index to zero at this second
        }
    }

    // For each number, calculate the earliest second it can be marked
    int earliestMarkTime = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            // If it's already zero, it can be marked instantly at second 1 (but still need to check sequence)
            earliestMarkTime = (earliestMarkTime > 1) ? earliestMarkTime : 1;
        } else {
            if (to_zero[i] == INT_MAX) {
                // Impossible to zero this index as it was never targeted
                return -1;
            }
            // We need to be able to mark this index, which means it must be zero and then marked
            int markTime = to_zero[i] + nums[i]; // One operation to zero + time needed to reduce to zero if required
            if (earliestMarkTime < markTime) {
                earliestMarkTime = markTime;
            }
        }
    }

    // Return the total time required to mark all indices
    return earliestMarkTime;
}
