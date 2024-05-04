#include <stdio.h>



int removeElement(int* nums, int numsSize, int val) {

    int writeIndex = 0;

    for (int i = 1; i < numsSize; i++) {

        if (nums[i] != val) {

            nums[writeIndex++] = nums[i - 1];

        }

    }

    return writeIndex;

}

