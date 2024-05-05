class Solution:
    def numberOfPairs(self, points: list[list[int]]) -> int:
        from collections import defaultdict

        # Dictionary to hold point counts in column and row dimensions.
        column_count = defaultdict(set)
        row_count = defaultdict(set)

        # Populate the dictionaries with points.
        for x, y in points:
            column_count[x].add((x, y))
            row_count[y].add((x, y))
        
        points_set = set(tuple(p) for p in points)
        count = 0

        # Iterate through all pairs of points
        for ax, ay in points:
            for bx, by in points:
                if ax <= bx and ay >= by:
                    # If Alice is at (ax, ay) and Bob is at (bx, by), then this is a valid configuration
                    # Check if there is any point in-between them on the fence
                    valid = True
                    if ax == bx:
                        # If vertical line (column), only check between y coordinates
                        for cy in range(by, ay + 1):
                            if (ax, cy) not in points_set:
                                valid = False
                                break
                    elif ay == by:
                        # If horizontal line (row), only check between x coordinates
                        for cx in range(ax, bx + 1):
                            if (cx, ay) not in points_set:
                                valid = False
                                break
                    else:
                        # For rectangle, check the border points
                        for cx in range(ax, bx + 1):
                            if (cx, ay) not in points_set or (cx, by) not in points_set:
                                valid = False
                                break
                        for cy in range(by, ay + 1):
                            if (ax, cy) not in points_set or (bx, cy) not in points_set:
                                valid = False
                                break

                    if valid:
                        count += 1

        return count
