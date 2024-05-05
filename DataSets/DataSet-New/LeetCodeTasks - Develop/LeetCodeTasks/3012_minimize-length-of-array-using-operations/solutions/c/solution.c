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
    if (numsSize == 1) return 1; // If there is only one element, we can't reduce further
    
    int resultGCD = nums[0];
    for (int i = 1; i < numsSize; i++) {
        resultGCD = gcd(resultGCD, nums[i]);
        if (resultGCD == 1) return 1; // Early exit if the GCD becomes 1
    }
    
    return resultGCD == 1 ? 1 : 2; // If GCD of all elements is 1, min length is 1, otherwise it is 2
}
