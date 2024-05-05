#include <vector>

class Solution {
public:
    int totalNQueens(int n) {
        std::vector<int> positions(n, -1); // Stores the row position of queen in each column
        int count = 0;
        solveNQueensHelper(positions, 0, count, n);
        return count;
    }

    void solveNQueensHelper(std::vector<int>& positions, int col, int& count, int n) {
        if (col == n) {
            count++; // Increment count when a valid solution is found
            return;
        }

        for (int row = 0; row < n; ++row) {
            if (isValid(positions, col, row)) {
                positions[col] = row; // Place queen
                solveNQueensHelper(positions, col + 1, count, n);
                positions[col] = -1; // Remove queen
            }
        }
    }

    bool isValid(std::vector<int>& positions, int currentCol, int currentRow) {
        for (int col = 0; col < currentCol; ++col) {
            int row = positions[col];
            if (row == currentRow) // Same row
                return false;
            if (abs(row - currentRow) == abs(col - currentCol)) // Same diagonal
                return false;
        }
        return true;
    }
};
