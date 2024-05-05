#include <stdio.h>

void sortColors(int* nums, int numsSize) {
    int low = 0, mid = 0, high = numsSize - 1;
    while (mid <= high) {
        switch (nums[mid]) {
            case 0:
                // Swap nums[low] and nums[mid]
                if (low != mid) {
                    nums[low] ^= nums[mid];
                    nums[mid] ^= nums[low];
                    nums[low] ^= nums[mid];
                }
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                // Swap nums[mid] and nums[high]
                if (mid != high) {
                    nums[mid] ^= nums[high];
                    nums[high] ^= nums[mid];
                    nums[mid] ^= nums[high];
                }
                high--;
                break;
        }
    }
}
