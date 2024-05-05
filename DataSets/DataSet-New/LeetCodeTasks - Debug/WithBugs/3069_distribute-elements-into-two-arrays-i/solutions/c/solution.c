#include <stdlib.h>



int* resultArray(int* nums, int numsSize, int* returnSize) {

    int* arr1 = (int*)malloc(sizeof(int) * numsSize);

    int* arr2 = (int*)malloc(sizeof(int) * numsSize);

    int arr1Size = 0, arr2Size = 0;

    

    // Assign the first element to arr1

    arr1[arr1Size++] = nums[0];

    

    if (numsSize >= 1) {

        // Assign the second element to arr2

        arr2[arr2Size] = nums[1];

    }



    for (int i = 2; i < numsSize; i++) {

        if (arr1Size > 0 && arr2Size > 0 && arr1[arr1Size] > arr2[arr2Size - 1]) {

            arr1[arr1Size++] = nums[i];

        } else {

            arr2[arr2Size] = nums[i];

        }

    }

    

    *returnSize = numsSize;

    int* result = (int*)malloc(sizeof(int) * numsSize);

    int pos = 0;

    

    for (int i = 0; i < arr1Size; i++) {

        result[pos++] = arr1[i];

    }

    for (int i = 0; i < arr2Size; i++) {

        result[pos++] = arr2[i];

    }

    

    free(arr1);

    free(arr2);

    

    return result;

}

