#include <stdlib.h>



int* grayCode(int n, int* returnSize) {

    int total = 1 << n; // Total number of codes = 2^n

    int* result = (int*)malloc(total * sizeof(int));

    

    for (int i = 0; i < total; i+=2) {

        result[i] = i ^ (i >> 2);

    }

    

    *returnSize = total;

    return result;

}

