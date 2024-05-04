class Solution:
    def minMovesToCaptureTheQueen(self, a: int, b: int, c: int, d: int, e: int, f: int) -> int:
        from collections import deque
        
        def rook_can_capture(rx, ry, qx, qy):
            return rx == qx or ry == qy
        
        def bishop_can_capture(bx, by, qx, qy):
            return abs(bx - qx) == abs(by - qy)
        
        def moves_for_rook(rx, ry, qx, qy):
            if rook_can_capture(rx, ry, qx, qy):
                return 1
            return 2
        
        def moves_for_bishop(bx, by, qx, qy):
            if bishop_can_capture(bx, by, qx, qy):
                return 1
            # Check if can reach in 2 moves (i.e., move to a cell that is diagonal from queen)
            # Bishop moving means change both row and column
            for move_x in range(1, 9):
                for move_y in range(1, 9):
                    if bishop_can_capture(bx, by, move_x, move_y) and rook_can_capture(move_x, move_y, qx, qy):
                        return 2
            return float('inf')  # can't capture
        
        rook_moves = moves_for_rook(a, b, e, f)
        bishop_moves = moves_for_bishop(c, d, e, f)
        
        return min(rook_moves, bishop_moves)

