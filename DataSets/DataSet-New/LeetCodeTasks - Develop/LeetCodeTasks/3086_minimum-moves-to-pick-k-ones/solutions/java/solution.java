import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public long minimumMoves(int[] nums, int k, int maxChanges) {
        int n = nums.length;
        // Prefix sum array to calculate number of 1s in a given range quickly.
        int[] prefixSum = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        // Deque to store indices of 1s in the current sliding window.
        Deque<Integer> indicesOfOnes = new ArrayDeque<>();
        // Initialize the left pointer for the sliding window.
        int left = 0;
        long minMoves = Long.MAX_VALUE;

        for (int right = 0; right < n; right++) {
            if (nums[right] == 1) {
                indicesOfOnes.addLast(right);
            }
            if (indicesOfOnes.size() > k) {
                indicesOfOnes.removeFirst();
                left = indicesOfOnes.peekFirst();
            }
            if (indicesOfOnes.size() == k) {
                long currentMin = 0;
                // Calculate the median index of the 1s within the window
                int medianIndex = indicesOfOnes.peekFirst() + k / 2;
                int pos = 0;
                for (int idx : indicesOfOnes) {
                    currentMin += Math.abs(idx - medianIndex) - pos++;
                }
                // Calculate the number of ones and zeros in the left and right of medianIndex
                int onesLeft = prefixSum[medianIndex] - prefixSum[left];
                int zerosLeft = medianIndex - left - onesLeft;
                int onesRight = prefixSum[right + 1] - prefixSum[medianIndex + 1];
                int zerosRight = right - medianIndex - onesRight;
                // To minimize moves, calculate the necessary shifts within the given changes
                long neededMoves = currentMin + Math.min(
                    (long) Math.max(0, zerosLeft - maxChanges) + Math.max(0, zerosRight - maxChanges),
                    (long) Math.max(0, zerosLeft) + Math.max(0, zerosRight)
                );
                minMoves = Math.min(minMoves, neededMoves);
            }
        }

        return minMoves;
    }
}
