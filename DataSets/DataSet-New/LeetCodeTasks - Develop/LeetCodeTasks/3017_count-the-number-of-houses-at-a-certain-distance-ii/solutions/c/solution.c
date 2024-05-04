#include <stdlib.h>

long long* countOfPairs(int n, int x, int y, int* returnSize) {
    long long* result = (long long*)malloc(n * sizeof(long long));
    for (int k = 1; k <= n; k++) {
        result[k - 1] = 0;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int distance = abs(i - j);
                distance = (distance < k) ? distance : k;
                if (abs(i - x) + abs(j - y) + 1 == k + distance) {
                    result[k - 1]++;
                }
            }
        }
    }
    
    *returnSize = n;
    return result;
}
