class Solution {
    public int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        // Check if the Rook can capture the Queen
        int rookMoves = (a == e || b == f) ? 1 : 2;

        // Check if the Bishop can capture the Queen
        boolean onSameDiagonal = Math.abs(c - e) == Math.abs(d - f);
        int bishopMoves = onSameDiagonal ? 1 : 2;

        // Calculate direct captures if pieces are already aligned
        if ((a == e && b == f) || (c == e && d == f)) {
            return 1; // Can capture directly if on same spot (in theory, not possible per constraints)
        }

        // For the rook to be able to capture the queen directly or in two moves
        if (a != e && b != f) {
            rookMoves = 2;
        } else {
            rookMoves = 1;
        }

        // For the bishop to be able to capture the queen directly or in two moves
        if (!onSameDiagonal) {
            bishopMoves = 2;
        } else {
            bishopMoves = 1;
        }

        // Return the minimum number of moves to capture the queen
        return Math.min(rookMoves, bishopMoves);
    }
}
