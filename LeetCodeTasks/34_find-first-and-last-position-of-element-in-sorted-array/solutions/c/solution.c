#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = -1;
    result[1] = -1;

    int left = 0, right = numsSize - 1;

    // Search for the left boundary
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            if (mid == 0 || nums[mid - 1] != target) {
                result[0] = mid;
                break;
            } else {
                right = mid - 1;
            }
        }
    }

    // Search for the right boundary
    left = 0;
    right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            if (mid == numsSize - 1 || nums[mid + 1] != target) {
                result[1] = mid;
                break;
            } else {
                left = mid + 1;
            }
        }
    }

    return result;
}
