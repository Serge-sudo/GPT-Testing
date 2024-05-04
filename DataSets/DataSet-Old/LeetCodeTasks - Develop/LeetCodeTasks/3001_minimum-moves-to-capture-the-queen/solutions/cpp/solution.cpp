#include <algorithm>

class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        // Rook movement: Check if it's already in line or can get in line with the queen
        int rook_moves = (a == e || b == f) ? 1 : 2;
        
        // Bishop movement: Check for the ability to move to the same diagonal as the queen
        int bishop_moves;
        if ((abs(e - c) == abs(f - d))) {
            bishop_moves = 1; // Already on the same diagonal
        } else if (((c + d) % 2) == ((e + f) % 2)) {
            // Can reach the same diagonal color, calculate moves
            // Move to an intermediate square then attack: typically two moves unless already aligned
            bishop_moves = 2;
        } else {
            bishop_moves = 3; // Bishop cannot reach the square of the queen's color in less than 2 moves
        }

        // Minimum moves to capture the queen
        return std::min(rook_moves, bishop_moves);
    }
};
