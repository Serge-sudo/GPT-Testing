class Solution {
    private int count = 0;

    public int totalNQueens(int n) {
        boolean[] cols = new boolean[n]; // columns
        boolean[] diag1 = new boolean[2 * n]; // main diagonals
        boolean[] diag2 = new boolean[2 * n]; // anti-diagonals
        backtrack(0, cols, diag1, diag2, n);
        return count;
    }

    private void backtrack(int row, boolean[] cols, boolean[] diag1, boolean[] diag2, int n) {
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {
            int d1 = row - col + n;
            int d2 = row + col;
            if (!cols[col] && !diag1[d1] && !diag2[d2]) {
                cols[col] = true;
                diag1[d1] = true;
                diag2[d2] = true;
                backtrack(row + 1, cols, diag1, diag2, n);
                cols[col] = false;
                diag1[d1] = false;
                diag2[d2] = false;
            }
        }
    }
}
