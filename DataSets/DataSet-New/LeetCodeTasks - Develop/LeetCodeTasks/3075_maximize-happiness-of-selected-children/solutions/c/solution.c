#include <stdlib.h>

long long maximumHappinessSum(int* happiness, int happinessSize, int k) {
    // Sort the happiness array in decreasing order to maximize selection.
    qsort(happiness, happinessSize, sizeof(int), (int (*)(const void *, const void *))[](const int *a, const int *b) {
        return *b - *a;
    });

    long long maxSum = 0;

    // Keep track of the maximum sum of selected happiness values.
    for (int i = 0; i < k; i++) {
        maxSum += happiness[i];
    }

    return maxSum;
}
