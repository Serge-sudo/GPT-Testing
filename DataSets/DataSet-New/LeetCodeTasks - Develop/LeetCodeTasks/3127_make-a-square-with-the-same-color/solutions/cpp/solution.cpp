#include <vector>

class Solution {
public:
    bool canMakeSquare(std::vector<std::vector<char>>& grid) {
        // Check all four possible 2x2 squares in the 3x3 grid
        for (int row = 0; row < 2; ++row) {
            for (int col = 0; col < 2; ++col) {
                // Count the number of 'B' and 'W' in the current 2x2 square
                int black = 0, white = 0;
                for (int i = 0; i < 2; ++i) {
                    for (int j = 0; j < 2; ++j) {
                        if (grid[row + i][col + j] == 'B') {
                            black++;
                        } else {
                            white++;
                        }
                    }
                }
                
                // If we can change at most one cell to make all same color
                if (black == 4 || white == 4 || black == 3 || white == 3) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
