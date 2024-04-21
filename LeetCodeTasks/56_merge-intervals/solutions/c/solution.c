#include <stdlib.h>

/**
 * Helper function to compare two intervals. Used for qsort.
 */
int compareIntervals(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    return intervalA[0] - intervalB[0];
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Sort intervals based on the start time
    qsort(intervals, intervalsSize, sizeof(int*), compareIntervals);

    // Allocate the initial output array
    int** result = malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = malloc(intervalsSize * sizeof(int));

    // Process the first interval
    int* currentInterval = intervals[0];
    result[0] = malloc(2 * sizeof(int));
    result[0][0] = currentInterval[0];
    result[0][1] = currentInterval[1];
    (*returnColumnSizes)[0] = 2;

    int resultIndex = 0;

    // Iterate through intervals and merge where necessary
    for (int i = 1; i < intervalsSize; ++i) {
        currentInterval = intervals[i];
        if (currentInterval[0] <= result[resultIndex][1]) {
            // There is overlap, merge the intervals
            if (currentInterval[1] > result[resultIndex][1]) {
                result[resultIndex][1] = currentInterval[1];
            }
        } else {
            // No overlap, start a new interval in the result
            resultIndex++;
            result[resultIndex] = malloc(2 * sizeof(int));
            result[resultIndex][0] = currentInterval[0];
            result[resultIndex][1] = currentInterval[1];
            (*returnColumnSizes)[resultIndex] = 2;
        }
    }

    // Update the number of merged intervals
    *returnSize = resultIndex + 1;

    return result;
}
