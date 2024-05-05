#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int maxOperations(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare_ints);
    
    int left = 0;
    int right = numsSize - 1;
    int max_operations = 0;
    int current_score = 0;
    
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (current_score == 0 || sum == current_score) {
            if (current_score == 0) current_score = sum;
            max_operations++;
            left++;
            right--;
        } else if (sum < current_score) {
            left++;
        } else {
            right--;
        }
    }
    
    return max_operations;
}
