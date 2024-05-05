class Solution {
    public int minimumOperationsToWriteY(int[][] grid) {
        int n = grid.length;
        int mid = n / 2;
        int[] countsY = new int[3];
        int[] countsNotY = new int[3];
        
        // Count occurrences of values in Y and not-Y regions
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (c == r || c == n - r - 1 || (r >= mid && c == mid)) {
                    // This cell is part of the Y
                    countsY[grid[r][c]]++;
                } else {
                    // This cell is not part of the Y
                    countsNotY[grid[r][c]]++;
                }
            }
        }
        
        int minOperations = Integer.MAX_VALUE;
        
        // Evaluate all combinations of setting Y to one value and not-Y to another
        for (int yVal = 0; yVal < 3; yVal++) {
            for (int notYVal = 0; notYVal < 3; notYVal++) {
                if (yVal != notYVal) {
                    int operationsY = 0;
                    int operationsNotY = 0;
                    for (int val = 0; val < 3; val++) {
                        if (val != yVal) {
                            operationsY += countsY[val]; // Change all non-yVal in Y region to yVal
                        }
                        if (val != notYVal) {
                            operationsNotY += countsNotY[val]; // Change all non-notYVal in not-Y region to notYVal
                        }
                    }
                    minOperations = Math.min(minOperations, operationsY + operationsNotY);
                }
            }
        }
        
        return minOperations;
    }
}
