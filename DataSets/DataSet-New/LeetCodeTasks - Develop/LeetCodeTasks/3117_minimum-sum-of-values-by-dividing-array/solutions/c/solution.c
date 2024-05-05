#include <limits.h>

int minimumValueSum(int* nums, int numsSize, int* andValues, int andValuesSize) {
    if (andValuesSize > numsSize) return -1;
    
    int** dp = (int**)malloc((andValuesSize + 1) * sizeof(int*));
    for (int i = 0; i <= andValuesSize; i++) {
        dp[i] = (int*)malloc((numsSize + 1) * sizeof(int));
        for (int j = 0; j <= numsSize; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    dp[0][0] = 0;

    for (int i = 1; i <= andValuesSize; i++) {
        for (int j = i; j <= numsSize; j++) {
            int and_so_far = nums[j-1];
            for (int k = j; k >= i; k--) {
                and_so_far &= nums[k-1];
                if (and_so_far == andValues[i-1]) {
                    if (dp[i-1][k-1] != INT_MAX) {
                        dp[i][j] = fmin(dp[i][j], dp[i-1][k-1] + nums[j-1]);
                    }
                }
            }
        }
    }

    int result = dp[andValuesSize][numsSize];
    for (int i = 0; i <= andValuesSize; i++) {
        free(dp[i]);
    }
    free(dp);

    return result == INT_MAX ? -1 : result;
}
