#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int minimumArrayLength(int* nums, int numsSize) {
    if (numsSize == 1) return 1;
    
    // Start with the gcd of the first two elements
    int result = gcd(nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++) {
        result = gcd(result, nums[i]);
        if (result == 1) return 1; // The minimum possible length we can achieve is 1
    }
    return result == 1 ? 1 : 2; // If the overall gcd is 1, array can be reduced to size 1, otherwise at least 2
}
