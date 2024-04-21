#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void findCombinations(int *candidates, int candidatesSize, int target, int *current, int currSize, int start, int ***results, int *returnSize, int **returnColumnSizes, int *buffer) {
    if (target == 0) {
        (*results)[*returnSize] = (int*)malloc(currSize * sizeof(int));
        memcpy((*results)[*returnSize], current, currSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = currSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i-1]) continue; // skip duplicates
        if (candidates[i] > target) break; // since array is sorted, no need to continue
        current[currSize] = candidates[i];
        findCombinations(candidates, candidatesSize, target - candidates[i], current, currSize + 1, i + 1, results, returnSize, returnColumnSizes, buffer);
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), compare);
    int **results = (int**)malloc(1000 * sizeof(int*)); // assuming 1000 combinations initially
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));
    *returnSize = 0;
    int *current = (int*)malloc(target * sizeof(int)); // maximum depth equal to target when using smallest elements
    
    findCombinations(candidates, candidatesSize, target, current, 0, 0, &results, returnSize, returnColumnSizes, current);
    
    free(current);
    
    if (*returnSize > 0) {
        results = (int**)realloc(results, *returnSize * sizeof(int*)); // resize results to the actual size
        *returnColumnSizes = (int*)realloc(*returnColumnSizes, *returnSize * sizeof(int)); // resize column sizes
    } else {
        free(results);
        results = NULL;
    }
    
    return results;
}
