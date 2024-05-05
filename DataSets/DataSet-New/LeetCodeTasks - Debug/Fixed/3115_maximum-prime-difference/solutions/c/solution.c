#include <stdbool.h>

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int maximumPrimeDifference(int* nums, int numsSize) {
    int first = -1, last = -1;
    for (int i = 0; i < numsSize; i++) {
        if (isPrime(nums[i])) {
            if (first == -1) first = i;
            last = i;
        }
    }
    return (first == -1 || last == -1) ? 0 : last - first;
}
