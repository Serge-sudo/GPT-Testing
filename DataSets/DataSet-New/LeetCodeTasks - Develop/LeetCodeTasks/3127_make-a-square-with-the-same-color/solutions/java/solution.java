class Solution {
    public boolean canMakeSquare(char[][] grid) {
        // Check all 2x2 sub-squares in the 3x3 grid
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int bCount = 0;
                int wCount = 0;
                
                // Count B's and W's in the current 2x2 square
                for (int x = i; x <= i + 1; x++) {
                    for (int y = j; y <= j + 1; y++) {
                        if (grid[x][y] == 'B') bCount++;
                        else wCount++;
                    }
                }
                
                // Check if we can make all the same with at most one change
                if (bCount == 4 || wCount == 4 || bCount == 3 || wCount == 3) {
                    return true;
                }
            }
        }
        return false;
    }
}
