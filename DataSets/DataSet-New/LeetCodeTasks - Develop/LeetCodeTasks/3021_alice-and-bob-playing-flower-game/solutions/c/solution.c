#include <stdio.h>

long long flowerGame(int n, int m) {
    long long count = 0;
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= m; ++y) {
            // Alice wins if the total number of flowers (x + y) is even
            // because she picks first and they take turns picking one each.
            if ((x + y) % 2 == 0) {
                count++;
            }
        }
    }
    return count;
}
