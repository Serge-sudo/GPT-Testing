#include <limits.h>



int mySqrt(int x) {

    if (x < 2) return x;



    long left = 1, right = x / 2, mid;

    while (left <= right) {

        mid = left + (right - left) / 2;

        long square = mid * mid;

        if (square == x) return mid;

        if (square < x) left = mid;

        else right = mid - 1;

    }

    return right;

}

