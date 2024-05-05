#include <limits.h>

int minOperations(int k) {
    if (k == 1) return 0;
    
    int sum = 1;
    int count = 0;
    
    // The optimal way to increase the sum quickly is to duplicate the largest values.
    while (sum < k) {
        int needed = k - sum;
        if (sum >= needed) {
            sum += sum;  // Doubling the sum.
            count++;     // One operation to double the highest possible value (or values).
        } else {
            int maxIncrement = INT_MAX - sum;
            if (maxIncrement > needed) {
                sum += needed;
                count += needed;  // Individual increments to the highest possible value.
            } else {
                sum += maxIncrement;
                count += maxIncrement;
            }
        }
    }
    
    return count;
}
