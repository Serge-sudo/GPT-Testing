#include <stdbool.h>

bool canMakeSquare(char** grid, int gridSize, int* gridColSize) {
    // There are only four possible 2x2 squares in a 3x3 grid
    int checkRows[] = {0, 0, 1, 1};
    int checkCols[] = {0, 1, 0, 1};
    
    // Check each 2x2 square
    for (int i = 0; i < 4; i++) {
        int r = checkRows[i];
        int c = checkCols[i];
        
        int bCount = 0, wCount = 0;
        
        // Check each cell in the 2x2 square
        for (int dr = 0; dr < 2; dr++) {
            for (int dc = 0; dc < 2; dc++) {
                if (grid[r + dr][c + dc] == 'B') bCount++;
                else if (grid[r + dr][c + dc] == 'W') wCount++;
            }
        }
        
        // If three or more cells are the same, we can make the whole 2x2 square the same by changing at most one cell
        if (bCount >= 3 || wCount >= 3) {
            return true;
        }
    }
    
    return false;
}
