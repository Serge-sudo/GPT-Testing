class Solution {
    public int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        // Determine if the rook can capture the queen in one move
        boolean rookCanCaptureInOne = (a == e || b == f);

        // Determine if the bishop can capture the queen in one move
        boolean bishopCanCaptureInOne = Math.abs(c - e) == Math.abs(d - f);

        // If either can capture in one move, return 1
        if (rookCanCaptureInOne || bishopCanCaptureInOne) {
            return 1;
        }

        // Checking if Rook can reach Queen in two moves: one to align, second to capture
        // Rook moves to the same row or column as the queen
        boolean rookTwoMoveCapture = (a != e && b != f);

        // Checking if Bishop can reach Queen in two moves
        // Bishop moves such that it changes both row and column but stays on a diagonal line
        boolean bishopTwoMoveCapture = false;
        if ((c + d) % 2 == (e + f) % 2) {  // They must be on the same color
            for (int i = 1; i <= 8; i++) {
                for (int j = 1; j <= 8; j++) {
                    if (Math.abs(c - i) == Math.abs(d - j) &&  // Path from Bishop to (i,j)
                        Math.abs(i - e) == Math.abs(j - f) &&  // Path from (i,j) to Queen
                        (c != i || d != j)) {  // Must actually move to a new square
                        bishopTwoMoveCapture = true;
                        break;
                    }
                }
                if (bishopTwoMoveCapture) {
                    break;
                }
            }
        }

        // If it is possible to capture in two moves, return 2
        if (rookTwoMoveCapture || bishopTwoMoveCapture) {
            return 2;
        }

        // Otherwise, return a high number since no solution in 1 or 2 moves exists
        // But per the constraints, the solution does not exceed 2 moves if the queen can be captured
        return 3;
    }
}
