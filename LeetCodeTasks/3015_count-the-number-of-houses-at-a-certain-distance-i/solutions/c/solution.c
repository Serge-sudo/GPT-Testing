#include <stdlib.h>

int* countOfPairs(int n, int x, int y, int* returnSize) {
    int* result = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        result[i] = 0;
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int dist_x = abs(i - x) + abs(j - y) + 1;
                int dist_y = abs(i - y) + abs(j - x) + 1;
                if (dist_x <= k || dist_y <= k)
                    result[k - 1]++;
            }
        }
    }
    
    *returnSize = n;
    return result;
}
