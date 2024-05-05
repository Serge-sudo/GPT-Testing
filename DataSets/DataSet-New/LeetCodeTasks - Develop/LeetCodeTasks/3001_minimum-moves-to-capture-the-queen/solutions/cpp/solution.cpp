#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        // The positions on the board are (a, b) for rook, (c, d) for bishop, and (e, f) for queen

        auto canRookCapture = [&](int rookX, int rookY, int targetX, int targetY) {
            return rookX == targetX || rookY == targetY;
        };

        auto canBishopCapture = [&](int bishopX, int bishopY, int targetX, int targetY) {
            return abs(bishopX - targetX) == abs(bishopY - targetY);
        };

        // Check if the pieces can directly capture the queen
        int moves = INT_MAX;
        if (canRookCapture(a, b, e, f)) moves = min(moves, 1);
        if (canBishopCapture(c, d, e, f)) moves = min(moves, 1);

        if (moves == 1) return 1; // If any piece can directly capture, return 1

        // If not, we need to calculate possible one-move reachable positions for rook and bishop
        set<pair<int, int>> rookMoves;
        set<pair<int, int>> bishopMoves;

        // Rook moves (horizontal and vertical)
        for (int i = 1; i <= 8; ++i) {
            if (i != a) rookMoves.emplace(i, b);  // Vertical moves
            if (i != b) rookMoves.emplace(a, i);  // Horizontal moves
        }

        // Bishop moves (all four diagonals)
        for (int offset = 1; offset <= 8; ++offset) {
            vector<pair<int, int>> directions = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
            for (auto& dir : directions) {
                int newX = c + dir.first * offset;
                int newY = d + dir.second * offset;
                if (newX >= 1 && newX <= 8 && newY >= 1 && newY <= 8) {
                    bishopMoves.emplace(newX, newY);
                }
            }
        }

        // Check if moving to any of the intermediate positions allows capturing the queen in the next move
        for (const auto& rm : rookMoves) {
            if (canRookCapture(rm.first, rm.second, e, f)) {
                moves = min(moves, 2);  // Rook moves to rm then captures queen
            }
        }

        for (const auto& bm : bishopMoves) {
            if (canBishopCapture(bm.first, bm.second, e, f)) {
                moves = min(moves, 2);  // Bishop moves to bm then captures queen
            }
        }

        return moves == INT_MAX ? -1 : moves; // If the queen cannot be captured, theoretically return -1 (though it's not expected per problem statement).
    }
};
