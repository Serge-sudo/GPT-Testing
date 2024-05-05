#include <limits.h>

long long minimumMoves(int* nums, int numsSize, int k, int maxChanges) {
    // Function to compute the minimal moves required to accumulate `k` ones at index `center`
    long long calculateCost(int center) {
        int left = center - 1, right = center + 1;
        long long moves = 0;
        int collected = nums[center] == 1 ? 1 : 0;
        int changes = maxChanges;

        while (collected < k) {
            int nextLeft = left >= 0 ? center - left : INT_MAX;
            int nextRight = right < numsSize ? right - center : INT_MAX;

            if (nextLeft < nextRight && left >= 0) {
                if (nums[left] == 1) {
                    moves += nextLeft;
                    collected++;
                } else if (changes > 0) {
                    moves += nextLeft;
                    changes--;
                    collected++;
                }
                left--;
            } else if (right < numsSize) {
                if (nums[right] == 1) {
                    moves += nextRight;
                    collected++;
                } else if (changes > 0) {
                    moves += nextRight;
                    changes--;
                    collected++;
                }
                right++;
            }
        }

        return moves;
    }

    long long minMoves = LLONG_MAX;
    
    // Evaluate the cost starting from each index where a '1' is initially or could potentially be turned into a '1'
    for (int i = 0; i < numsSize; i++) {
        long long cost = calculateCost(i);
        if (cost < minMoves) {
            minMoves = cost;
        }
    }

    return minMoves;
}
