#include <stdlib.h>

long long* countOfPairs(int n, int x, int y, int* returnSize) {
    *returnSize = n;
    long long* result = malloc(n * sizeof(long long));
    if (!result) return NULL;
    
    // Initialize result array to zero
    for (int i = 0; i < n; i++) {
        result[i] = 0;
    }
    
    // Ensure x <= y for simpler calculations
    if (x > y) {
        int temp = x;
        x = y;
        y = temp;
    }
    
    // Using Floyd-Warshall-like reasoning, or more simply, dynamic reachability
    int dist = y - x;
    for (int k = 1; k <= n; k++) {
        long long count = 0;
        // For each house i, calculate the distances to other houses and count the ones that are exactly k
        for (int i = 1; i <= n; i++) {
            int j1 = i + k; // Forward k
            int j2 = i - k; // Backward k
            
            // Validity check for j1
            if (j1 <= n) {
                count++;
            }
            // Validity check for j2
            if (j2 >= 1) {
                count++;
            }
        }
        
        // Also, compute using the x to y shortcut, considering how it might shortcut previous results
        // Forward and backward considering shortcut distances
        for (int i = 1; i <= n; i++) {
            // Minimum distance using x-y shortcut
            int via_x = abs(i - x) + 1 + abs(y - (i + k));
            int via_y = abs(i - y) + 1 + abs(x - (i + k));
            if (i + k <= n && (via_x == k || via_y == k)) {
                count++;
            }
            via_x = abs(i - x) + 1 + abs(y - (i - k));
            via_y = abs(i - y) + 1 + abs(x - (i - k));
            if (i - k >= 1 && (via_x == k || via_y == k)) {
                count++;
            }
        }
        
        // Record the result
        result[k - 1] = count;
    }
    
    return result;
}
