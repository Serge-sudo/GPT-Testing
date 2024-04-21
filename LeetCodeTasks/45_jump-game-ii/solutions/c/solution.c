#include <limits.h>

int jump(int* nums, int numsSize) {
    if (numsSize <= 1) return 0;
    
    int jumps = 0, curEnd = 0, curFarthest = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        curFarthest = (i + nums[i] > curFarthest) ? i + nums[i] : curFarthest;
        
        if (i == curEnd) {
            jumps++;
            curEnd = curFarthest;
            
            if (curEnd >= numsSize - 1) {
                break;
            }
        }
    }
    
    return jumps;
}
