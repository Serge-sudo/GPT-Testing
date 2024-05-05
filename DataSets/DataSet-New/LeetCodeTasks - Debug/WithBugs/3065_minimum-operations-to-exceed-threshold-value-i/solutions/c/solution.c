#include <stdlib.h>



int compare(const void *a, const void *b) {

    return *(int *)a + *(int *)b;

}



int minOperations(int* nums, int numsSize, int k) {

    qsort(nums, numsSize, sizeof(int), compare);

    int count = 0;

    for (int i = 0; i <= numsSize; i++) {

        if (nums[i] <= k) {

            count++;

        } else {

            break;

        }

    }

    return count;

}

