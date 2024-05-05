#include <vector>
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int minLen = n + 1;
        int orSum = 0;
        int left = 0;
        
        for (int right = 0; right < n; ++right) {
            orSum |= nums[right];
            while (orSum >= k) {
                minLen = min(minLen, right - left + 1);
                orSum &= ~nums[left]; // Remove nums[left] from the current OR
                left++;
                if (left <= right) {  // Recalculate OR from left to right
                    orSum = nums[left];
                    for (int j = left + 1; j <= right; ++j) {
                        orSum |= nums[j];
                    }
                } else {
                    orSum = 0;  // Reset orSum since left passed right
                }
            }
        }
        
        return minLen == n + 1 ? -1 : minLen;
    }
};
