#include <stdlib.h>

int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
    int rook_moves = abs(a - e) > 0 && abs(b - f) > 0 ? 2 : 1;
    int bishop_moves = 1;
    if (((e - c) == (f - d)) || ((e - c) == -(f - d))) {
        // Bishop can move to the position in one move
        bishop_moves = 1;
    } else if ((abs(e - c) % 2) == (abs(f - d) % 2)) {
        // Target square is reachable by bishop but not in one move
        bishop_moves = 2;
    } else {
        // Bishop cannot reach the square at all (different color square)
        bishop_moves = 1000; // Large number to signify impossibility
    }
    if (a == e || b == f) {
        // Rook can directly move to the queen's position
        rook_moves = 1;
    }
    // Return the minimum moves required considering both pieces
    return rook_moves < bishop_moves ? rook_moves : bishop_moves;
}
