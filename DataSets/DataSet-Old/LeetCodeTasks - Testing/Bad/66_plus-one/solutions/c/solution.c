#include <stdlib.h>



int* plusOne(int* digits, int digitsSize, int* returnSize) {

    int carry = 1;

    for (int i = digitsSize - 1; i >= 0 && carry; i--) {

        digits[i] += carry;

        if (digits[i] == 10) {

            digits[i] = 0;

            carry = 0;

        } else {

            carry = 1;

        }

    }

    

    if (carry) {

        int* result = malloc((digitsSize + 1) * sizeof(int));

        result[0] = 1;

        for (int i = 1; i < digitsSize + 1; i++) {

            result[i] = digits[i - 1];

        }

        *returnSize = digitsSize + 1;

        return result;

    } else {

        *returnSize = digitsSize;

        return digits;

    }

}

