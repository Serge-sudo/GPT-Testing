from typing import List

class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        # Converting points into a set for faster lookup
        point_set = set(tuple(point) for point in points)
        valid_pairs = 0
        
        # We need to check each point against every other to find suitable pairs
        for i in range(len(points)):
            x1, y1 = points[i]
            for j in range(len(points)):
                if i != j:
                    x2, y2 = points[j]
                    
                    # Alice should be at the upper left corner, and Bob at the lower right corner
                    if x1 <= x2 and y1 >= y2:
                        # We must ensure no other points lie on the rectangle edges formed by (x1, y1) and (x2, y2)
                        no_interior_points = True
                        for x, y in points:
                            # If it's neither Alice nor Bob and lies inside or on the boundary of the rectangle
                            if (x1 < x < x2 and y1 > y > y2) or (
                                (x == x1 or x == x2) and y1 >= y >= y2) or (
                                (y == y1 or y == y2) and x1 <= x <= x2):
                                no_interior_points = False
                                break
                        
                        if no_interior_points:
                            valid_pairs += 1
        
        return valid_pairs
