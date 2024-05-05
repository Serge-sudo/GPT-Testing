public class Solution {
    public int countSubmatrices(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length;
        int count = 0;

        // Build a prefix sum matrix
        int[][] prefixSum = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = grid[i - 1][j - 1]
                    + prefixSum[i - 1][j]
                    + prefixSum[i][j - 1]
                    - prefixSum[i - 1][j - 1];
            }
        }

        // Enumerate all submatrices containing the top-left element (0,0)
        for (int r1 = 0; r1 < m; r1++) {
            for (int c1 = 0; c1 < n; c1++) {
                for (int r2 = r1; r2 < m; r2++) {
                    for (int c2 = c1; c2 < n; c2++) {
                        int sum = prefixSum[r2 + 1][c2 + 1]
                            - prefixSum[r1][c2 + 1]
                            - prefixSum[r2 + 1][c1]
                            + prefixSum[r1][c1];
                        if (sum <= k) {
                            count++;
                        }
                    }
                }
            }
        }

        return count;
    }
}
