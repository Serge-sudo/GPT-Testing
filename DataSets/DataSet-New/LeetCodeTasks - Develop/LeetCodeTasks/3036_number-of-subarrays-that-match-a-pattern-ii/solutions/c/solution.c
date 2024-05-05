#include <stdbool.h>

int countMatchingSubarrays(int* nums, int numsSize, int* pattern, int patternSize) {
    int count = 0;
    int m = patternSize;
    
    for (int i = 0; i <= numsSize - m - 1; ++i) {
        bool matches = true;
        
        for (int k = 0; k < m; ++k) {
            if ((pattern[k] == 1 && nums[i + k + 1] <= nums[i + k]) ||
                (pattern[k] == 0 && nums[i + k + 1] != nums[i + k]) ||
                (pattern[k] == -1 && nums[i + k + 1] >= nums[i + k])) {
                matches = false;
                break;
            }
        }
        
        if (matches) {
            ++count;
        }
    }
    
    return count;
}
