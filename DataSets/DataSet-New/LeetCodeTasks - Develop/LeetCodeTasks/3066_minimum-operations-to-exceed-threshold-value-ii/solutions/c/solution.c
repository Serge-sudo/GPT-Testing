#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int minOperations(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int count = 0;
    
    // Using two indices, left starting from the beginning and right from the end
    int left = 0;
    int right = numsSize - 1;
    
    // While we haven't processed all elements to be >= k
    while (nums[right] < k) {
        if (left == right) { // If only one element left that is less than k, return -1 (although problem ensures solution always exists)
            return -1; 
        }
        
        // Perform the operation as described
        int x = nums[left];
        int y = nums[left + 1];
        int new_val = x * 2 + y;
        
        // Increment operations count
        count++;
        
        // Move left pointer to effectively remove the two smallest elements
        left += 2;
        
        // Place new_val into the sorted position (from right to left)
        int insertPos = right;
        while (insertPos > left && nums[insertPos - 1] > new_val) {
            nums[insertPos] = nums[insertPos - 1];
            insertPos--;
        }
        nums[insertPos] = new_val;
        
        // Decrease right index if the last element is already >= k
        while (right >= left && nums[right] >= k) {
            right--;
        }
    }
    
    return count;
}
