#include <limits.h>

int earliestSecondToMarkIndices(int* nums, int numsSize, int* changeIndices, int changeIndicesSize) {
    // Array to track if an index is marked
    int marked[numsSize];
    for (int i = 0; i < numsSize; i++) {
        marked[i] = 0;
    }
    
    // Array to count how many times we need to mark each index to zero it out
    int needs[numsSize];
    for (int i = 0; i < numsSize; i++) {
        needs[i] = nums[i];
    }
    
    // Latest time we need to be able to mark each index
    int latestMarkTime[numsSize];
    for (int i = 0; i < numsSize; i++) {
        latestMarkTime[i] = INT_MAX;
    }
    
    // Process changeIndices in reverse to determine the latest point each index can be marked
    for (int i = changeIndicesSize - 1; i >= 0; i--) {
        int idx = changeIndices[i] - 1;  // Convert to 0-based index
        if (needs[idx] > 0) {
            needs[idx]--;
            latestMarkTime[idx] = i + 1;  // Store 1-based index
        }
    }
    
    // Check if all indices can be marked at their respective latest times
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0 && latestMarkTime[i] == INT_MAX) {
            return -1;  // Cannot mark this index because it was never brought to zero
        }
    }
    
    // Find the maximum of the latest mark times where marking was possible
    int earliestSecond = -1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            earliestSecond = earliestSecond > latestMarkTime[i] ? earliestSecond : latestMarkTime[i];
        }
    }
    
    return earliestSecond;
}
