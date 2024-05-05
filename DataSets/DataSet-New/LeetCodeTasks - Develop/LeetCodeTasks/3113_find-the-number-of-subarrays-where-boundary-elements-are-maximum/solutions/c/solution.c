#include <stdio.h>

long long numberOfSubarrays(int* nums, int numsSize) {
    long long count = 0;
    for (int i = 0; i < numsSize; i++) {
        int max = nums[i];
        // Look for the rightmost occurrence of nums[i]
        int j = i;
        while (j < numsSize && nums[j] == nums[i]) {
            j++;
        }
        j--; // Adjust to the last occurrence of nums[i]
        
        // Calculate number of subarrays where nums[i] is the max and it appears at both ends
        long long len = j - i + 1;
        count += len * (len + 1) / 2;
        
        i = j; // Skip to the end of current sequence of the same element
    }
    return count;
}
