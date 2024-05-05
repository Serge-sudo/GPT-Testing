from typing import List

class Solution:
    def minRectanglesToCoverPoints(self, points: List[List[int]], w: int) -> int:
        # Sorting points based on the x-coordinate
        points.sort()
        rectangles = 0
        i = 0
        n = len(points)
        
        while i < n:
            rectangles += 1  # We are going to use a new rectangle
            # The starting x of the rectangle
            start_x = points[i][0]
            # The maximum x for this rectangle
            max_x = start_x + w
            
            # Define the height needed to cover all points within the width limit
            max_y = 0
            while i < n and points[i][0] <= max_x:
                max_y = max(max_y, points[i][1])
                i += 1
                
        return rectangles
