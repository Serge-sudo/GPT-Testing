class Solution:
    def minMovesToCaptureTheQueen(self, a: int, b: int, c: int, d: int, e: int, f: int) -> int:
        def can_rook_capture(rx, ry, qx, qy):
            return rx == qx or ry == qy

        def can_bishop_capture(bx, by, qx, qy):
            return abs(bx - qx) == abs(by - qy)

        # Checking direct captures
        if can_rook_capture(a, b, e, f):
            return 1
        if can_bishop_capture(c, d, e, f):
            return 1
        
        # Check for 2-move captures with the rook
        # Move rook horizontally to match queen's column and then vertically
        # Or move rook vertically to match queen's row and then horizontally
        # Checking each cell the rook can move to directly
        for x in range(1, 9):
            if x != a and can_rook_capture(x, b, e, f):
                if (x == c and b == d) or (x == e and b == f):  # Check if blocked by bishop or queen herself
                    continue
                if can_rook_capture(a, b, x, b):
                    return 2
            if x != b and can_rook_capture(a, x, e, f):
                if (a == c and x == d) or (a == e and x == f):  # Check if blocked by bishop or queen herself
                    continue
                if can_rook_capture(a, b, a, x):
                    return 2
        
        # Check for 2-move captures with the bishop by moving to a cell that can then capture the queen
        # Moving the bishop to all possible diagonals it can move to, then checking if it can capture from there
        for dx in [-1, 1]:
            for dy in [-1, 1]:
                # Scan each diagonal
                nx, ny = c + dx, d + dy
                while 1 <= nx <= 8 and 1 <= ny <= 8:
                    if (nx, ny) == (a, b):  # blocked by the rook
                        break
                    if can_bishop_capture(nx, ny, e, f):
                        if can_bishop_capture(c, d, nx, ny):
                            return 2
                    nx += dx
                    ny += dy

        return float('inf')  # If no path found, although all valid inputs should have a solution within two moves.
