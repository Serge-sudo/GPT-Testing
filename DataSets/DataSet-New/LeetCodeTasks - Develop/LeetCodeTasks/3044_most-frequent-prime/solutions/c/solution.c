#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6)
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    return true;
}

int mostFrequentPrime(int** mat, int matSize, int* matColSize) {
    int directions[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    int maxM = matSize, maxN = matColSize[0];
    int* primesFreq = calloc(1000000, sizeof(int));
    
    for (int i = 0; i < maxM; i++) {
        for (int j = 0; j < maxN; j++) {
            for (int d = 0; d < 8; d++) {
                int x = i, y = j;
                int num = 0;
                while (x >= 0 && x < maxM && y >= 0 && y < maxN) {
                    num = num * 10 + mat[x][y];
                    if (num > 10 && isPrime(num)) {
                        primesFreq[num]++;
                    }
                    x += directions[d][0];
                    y += directions[d][1];
                }
            }
        }
    }

    int mostFreqPrime = -1;
    int maxFrequency = 0;
    for (int num = 10; num < 1000000; num++) {
        if (primesFreq[num] > maxFrequency || (primesFreq[num] == maxFrequency && num > mostFreqPrime)) {
            if (primesFreq[num] > 0 && isPrime(num)) {
                mostFreqPrime = num;
                maxFrequency = primesFreq[num];
            }
        }
    }

    free(primesFreq);
    return mostFreqPrime;
}
