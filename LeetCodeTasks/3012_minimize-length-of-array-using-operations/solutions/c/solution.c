#include <stdlib.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int minimumArrayLength(int* nums, int numsSize) {
    int length = numsSize;
    int i, j, *new_nums;

    while (length > 1) {
        int min_i = 0, min_j = 1;
        int min_mod = nums[0] % nums[1];
        for (i = 0; i < length; i++) {
            for (j = i + 1; j < length; j++) {
                int mod = nums[i] % nums[j];
                if (mod < min_mod) {
                    min_i = i;
                    min_j = j;
                    min_mod = mod;
                }
            }
        }
        if (min_mod == 0) {
            return 1;
        }
        int gcd_ij = gcd(nums[min_i], nums[min_j]);
        int new_size = length - 1;
        new_nums = (int*)malloc(new_size * sizeof(int));
        if (new_nums == NULL) {
            // Handle memory allocation error
            return -1;
        }
        int index = 0;
        for (i = 0; i < length; i++) {
            if (i != min_i && i != min_j) {
                new_nums[index++] = nums[i];
            }
        }
        new_nums[index] = gcd_ij;
        free(nums);
        nums = new_nums;
        length = new_size;
    }
    return length;
}
