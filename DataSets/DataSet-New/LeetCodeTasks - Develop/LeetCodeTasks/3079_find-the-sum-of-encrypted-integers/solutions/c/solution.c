#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sumOfEncryptedInt(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        int n = nums[i];
        int maxDigit = 0;
        while (n > 0) {
            int currentDigit = n % 10;
            if (currentDigit > maxDigit) {
                maxDigit = currentDigit;
            }
            n /= 10;
        }
        int encryptedValue = 0;
        int multiplier = 1;
        for (int j = nums[i]; j > 0; j /= 10) {
            encryptedValue += maxDigit * multiplier;
            multiplier *= 10;
        }
        sum += encryptedValue;
    }
    return sum;
}
