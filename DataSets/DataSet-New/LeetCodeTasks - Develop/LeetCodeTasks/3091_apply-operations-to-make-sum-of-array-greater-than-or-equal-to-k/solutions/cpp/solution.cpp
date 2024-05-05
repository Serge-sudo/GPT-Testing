#include <cmath>

class Solution {
public:
    int minOperations(int k) {
        int operations = 0;
        int sum = 1;
        
        while (sum < k) {
            if (sum * 2 <= k) {
                // Doubling the entire array if the double sum is still less than or equal to k
                operations++;  // This operation is a duplication of the entire array
                sum *= 2;
            } else {
                // Otherwise, calculate the minimum increases needed to reach or exceed k
                int needed = k - sum;
                operations += needed;  // This many individual increments are required
                break;
            }
        }
        
        return operations;
    }
};
