#include <stdlib.h>

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int **result = malloc(sizeof(int*) * (intervalsSize + 1));
    *returnColumnSizes = malloc(sizeof(int) * (intervalsSize + 1));
    int newSize = 0;
    int i = 0;
    
    // Add intervals before the newInterval
    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        result[newSize] = malloc(sizeof(int) * 2);
        result[newSize][0] = intervals[i][0];
        result[newSize][1] = intervals[i][1];
        (*returnColumnSizes)[newSize] = 2;
        newSize++;
        i++;
    }
    
    // Merge intervals with newInterval
    while (i < intervalsSize && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = newInterval[0] < intervals[i][0] ? newInterval[0] : intervals[i][0];
        newInterval[1] = newInterval[1] > intervals[i][1] ? newInterval[1] : intervals[i][1];
        i++;
    }
    result[newSize] = malloc(sizeof(int) * 2);
    result[newSize][0] = newInterval[0];
    result[newSize][1] = newInterval[1];
    (*returnColumnSizes)[newSize] = 2;
    newSize++;
    
    // Add remaining intervals after the newInterval
    while (i < intervalsSize) {
        result[newSize] = malloc(sizeof(int) * 2);
        result[newSize][0] = intervals[i][0];
        result[newSize][1] = intervals[i][1];
        (*returnColumnSizes)[newSize] = 2;
        newSize++;
        i++;
    }
    
    *returnSize = newSize;
    return result;
}
