#include <stdlib.h>
#include <limits.h>

#define MOD 1000000007

int compare(const void *a, const void *b) {
    long long num1 = *(const int*)a;
    long long num2 = *(const int*)b;
    if (num1 > num2) return 1;
    if (num1 < num2) return -1;
    return 0;
}

int sumOfPowers(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);

    long long totalPower = 0;
    long long *comb = malloc((numsSize + 1) * sizeof(long long));
    comb[0] = 1;
    
    for (int i = 1; i <= numsSize; i++) {
        comb[i] = 1;
        for (int j = i - 1; j > 0; j--) {
            comb[j] = (comb[j] + comb[j - 1]) % MOD;
        }
    }
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            long long power = (nums[j] - nums[i]) % MOD;
            if (power < 0) power += MOD;
            long long countLeft = comb[i];
            long long countRight = (j < numsSize - 1) ? comb[numsSize - j - 1] : 1;
            long long combos = countLeft * countRight % MOD;
            
            for (int t = 2; t < k; t++) {
                combos = combos * (j - i) % MOD;
            }
            
            totalPower = (totalPower + power * combos % MOD) % MOD;
        }
    }
    
    free(comb);
    return totalPower;
}
