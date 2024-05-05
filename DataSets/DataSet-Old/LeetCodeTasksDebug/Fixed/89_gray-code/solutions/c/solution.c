#include <stdlib.h>

int* grayCode(int n, int* returnSize) {
    int total = 1 << n; // Total number of codes = 2^n
    int* result = (int*)malloc(total * sizeof(int));
    
    for (int i = 0; i < total; i++) {
        result[i] = i ^ (i >> 1); // Generating the gray code sequence
    }

    *returnSize = total;
    return result;
}
