#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int sumOfPower(int* nums, int numsSize, int k) {
    int* dp = (int*)calloc(k + 1, sizeof(int));
    dp[0] = 1;
    int total_power = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        for (int j = k; j >= num; j--) {
            dp[j] = (dp[j] + dp[j - num]) % MOD;
        }
    }
    
    total_power = dp[k];
    
    free(dp);
    return total_power;
}
