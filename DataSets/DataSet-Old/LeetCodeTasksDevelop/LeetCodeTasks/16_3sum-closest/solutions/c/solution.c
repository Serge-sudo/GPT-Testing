#include <stdlib.h> // for qsort
#include <limits.h> // for INT_MAX

int compareInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compareInt);
    int closestSum = 0;
    int smallestDifference = INT_MAX;
    
    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            int diff = abs(target - sum);
            
            if (diff < smallestDifference) {
                smallestDifference = diff;
                closestSum = sum;
            }
            
            if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            } else {
                return sum; // exactly equal to target
            }
        }
    }
    return closestSum;
}
