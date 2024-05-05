class Solution {
    public int earliestSecondToMarkIndices(int[] nums, int[] changeIndices) {
        int n = nums.length;
        int m = changeIndices.length;

        // Tracking which indices are marked
        boolean[] marked = new boolean[n + 1];
        // Tracking the number of marks
        int markedCount = 0;

        // Step count required to reduce each index to zero
        int[] stepsToZero = new int[n + 1];

        // Initially populate the stepsToZero array based on nums value
        for (int i = 1; i <= n; i++) {
            stepsToZero[i] = nums[i - 1];
            if (stepsToZero[i] == 0) { // Pre-marked as it's already zero
                marked[i] = true;
                markedCount++;
            }
        }

        // If all indices are marked initially
        if (markedCount == n) {
            return 0;
        }

        // Process each second up to m
        for (int second = 1; second <= m; second++) {
            int index = changeIndices[second - 1];
            
            // If index is already marked or can be marked now
            if (stepsToZero[index] == 0) {
                if (!marked[index]) {
                    marked[index] = true;
                    markedCount++;
                }
            } else {
                // Decrement the required value to mark this index
                stepsToZero[index]--;
            }

            // If all indices are now marked
            if (markedCount == n) {
                return second;
            }
        }

        // If not all indices could be marked by the end of m seconds
        return -1;
    }
}
