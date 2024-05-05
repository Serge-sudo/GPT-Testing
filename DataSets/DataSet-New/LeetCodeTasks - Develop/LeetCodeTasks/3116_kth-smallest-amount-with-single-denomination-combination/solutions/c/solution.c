#include <stdlib.h>

long long findKthSmallest(int* coins, int coinsSize, int k) {
    // Using Min-Heap approach
    long long min = 1;
    long long max = 2000000000; // Approximate high bound (considering constraints)
    
    while (min < max) {
        long long mid = (min + max) / 2;
        long long count = 0;

        for (int i = 0; i < coinsSize; i++) {
            count += mid / coins[i];
        }

        if (count < k) {
            min = mid + 1;
        } else {
            max = mid;
        }
    }

    return min;
}
