class Solution {
    public long numberOfRightTriangles(int[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        long count = 0;
        
        // Count the number of 1s in each row and each column
        int[] rowCount = new int[rows];
        int[] colCount = new int[cols];
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    rowCount[r]++;
                    colCount[c]++;
                }
            }
        }
        
        // Calculate the number of right triangles using the intersection points
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    // (rowCount[r] - 1) choices in the row, (colCount[c] - 1) choices in the column
                    count += (rowCount[r] - 1) * (colCount[c] - 1);
                }
            }
        }
        
        return count;
    }
}
