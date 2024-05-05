#include <stdlib.h>

int* countOfPairs(int n, int x, int y, int* returnSize) {
    // Allocate memory for the result array
    int* result = (int*)calloc(n + 1, sizeof(int));
    *returnSize = n;
    
    // Always ensure x <= y
    if (x > y) {
        int temp = x;
        x = y;
        y = temp;
    }
    
    // Main loop to count pairs for each distance k
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            int j1 = i + k; // forward neighbor at distance k
            int j2 = i - k; // backward neighbor at distance k
            
            // Check if j1 is a valid house number
            if (j1 <= n) {
                int d1 = abs(i - j1);
                int d2 = abs(i - x) + 1 + abs(y - j1);
                int d3 = abs(i - y) + 1 + abs(x - j1);
                if (d1 == k || d2 == k || d3 == k) {
                    result[k]++;
                }
            }
            
            // Check if j2 is a valid house number
            if (j2 >= 1) {
                int d1 = abs(i - j2);
                int d2 = abs(i - x) + 1 + abs(y - j2);
                int d3 = abs(i - y) + 1 + abs(x - j2);
                if (d1 == k || d2 == k || d3 == k) {
                    result[k]++;
                }
            }
        }
    }
    
    return result;
}
