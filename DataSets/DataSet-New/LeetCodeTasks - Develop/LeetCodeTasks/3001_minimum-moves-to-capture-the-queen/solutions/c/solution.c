#include <stdlib.h>

int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
    int rook_moves = abs(a - e) + abs(b - f) - 1;  // Moves needed for rook to reach queen directly
    int bishop_moves = 2;  // Assume it takes 2 moves unless it can capture in 1

    // Check if bishop is on the same diagonal as the queen
    if (abs(c - e) == abs(d - f)) {
        bishop_moves = 1;  // Bishop can directly capture the queen in one move
    }
    
    // Check if the bishop can capture the queen in 1 move by being in a position adjacent to its line
    if ((abs(c - e) % 2 == 0 && abs(d - f) % 2 == 0) || (abs(c - e) % 2 == 1 && abs(d - f) % 2 == 1)) {
        // If the target and bishop are on the same color square
        int bishop_to_target = (abs(c - e) + abs(d - f)) / 2;
        bishop_moves = bishop_to_target;
    }

    // Determine the minimum moves by comparing optimized rook and bishop moves
    int min_moves = (rook_moves < bishop_moves) ? rook_moves : bishop_moves;
    return min_moves;
}
