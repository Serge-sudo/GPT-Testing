class Solution {
    public int minimumOperations(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int minOps = 0;

        // Ensure all columns have the same value for each row
        for (int j = 0; j < n; j++) {
            for (int i = 1; i < m; i++) {
                if (grid[i][j] != grid[i - 1][j]) {
                    minOps++;
                    grid[i][j] = grid[i - 1][j]; // Simulate the operation for understanding
                }
            }
        }
        
        // Ensure no two adjacent cells in the same row are equal
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] == grid[i][j - 1]) {
                    minOps++;
                    // Just simulate a change without specifying the new value
                    grid[i][j] = grid[i][j] + 1; // This is just to simulate; In actual scenario, decide based on context
                }
            }
        }

        return minOps;
    }
}
