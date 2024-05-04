#include <stdio.h>
#include <stdlib.h>

void findCombinations(int *candidates, int candidatesSize, int target, int** results, int* resultCount, int** resultColumnSizes, int* currentCombination, int currentSize, int startIndex) {
    if (target == 0) {
        results[*resultCount] = (int*) malloc(currentSize * sizeof(int));
        for (int i = 0; i < currentSize; i++) {
            results[*resultCount][i] = currentCombination[i];
        }
        (*resultColumnSizes)[*resultCount] = currentSize;
        (*resultCount)++;
        return;
    }
    
    for (int i = startIndex; i < candidatesSize; i++) {
        if (candidates[i] > target) {
            continue;
        }
        currentCombination[currentSize] = candidates[i];
        findCombinations(candidates, candidatesSize, target - candidates[i], results, resultCount, resultColumnSizes, currentCombination, currentSize + 1, i);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int** results = (int**) malloc(150 * sizeof(int*));
    *returnColumnSizes = (int*) malloc(150 * sizeof(int));
    int* currentCombination = (int*) malloc(target * sizeof(int));
    *returnSize = 0;

    findCombinations(candidates, candidatesSize, target, results, returnSize, returnColumnSizes, currentCombination, 0, 0);
    
    free(currentCombination);
    return results;
}
