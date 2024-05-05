#include <stdbool.h>

int countMatchingSubarrays(int* nums, int numsSize, int* pattern, int patternSize) {
    int count = 0;
    for (int i = 0; i <= numsSize - patternSize - 1; i++) {
        bool match = true;
        for (int k = 0; k < patternSize; k++) {
            if ((pattern[k] == 1 && nums[i + k + 1] <= nums[i + k]) ||
                (pattern[k] == 0 && nums[i + k + 1] != nums[i + k]) ||
                (pattern[k] == -1 && nums[i + k + 1] >= nums[i + k])) {
                match = false;
                break;
            }
        }
        if (match) {
            count++;
        }
    }
    return count;
}
