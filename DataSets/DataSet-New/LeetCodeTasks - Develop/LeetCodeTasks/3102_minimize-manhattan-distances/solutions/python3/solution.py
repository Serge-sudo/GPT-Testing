class Solution:
    def minimumDistance(self, points: list[list[int]]) -> int:
        def manhattan(p1, p2):
            return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])
        
        def get_extreme_points():
            max_x, max_y = -float('inf'), -float('inf')
            min_x, min_y = float('inf'), float('inf')
            for x, y in points:
                if x + y > max_x + max_y:
                    max_x, max_y = x, y
                if x + y < min_x + min_y:
                    min_x, min_y = x, y
                if x - y > max_x - max_y:
                    max_x_neg, max_y_neg = x, y
                if x - y < min_x_neg - min_y_neg:
                    min_x_neg, min_y_neg = x, y
            return (max_x, max_y), (min_x, min_y), (max_x_neg, max_y_neg), (min_x_neg, min_y_neg)
        
        n = len(points)
        if n == 3:  # with only 3 points, removing any one will leave us with only one pair to consider
            return min(manhattan(points[0], points[1]), manhattan(points[0], points[2]), manhattan(points[1], points[2]))
        
        # Finding the extreme points based on `x + y` and `x - y` criteria
        max1, min1, max2, min2 = get_extreme_points()
        
        # Check the max distances by removing one point at a time
        min_max_distance = float('inf')
        for i in range(n):
            current_point = points[i]
            candidates = [max1, min1, max2, min2]
            # Consider other extreme points when current point is removed
            max_distance_when_removed = 0
            for p1 in candidates:
                if p1 == current_point:
                    continue
                for p2 in candidates:
                    if p2 == current_point or p1 == p2:
                        continue
                    max_distance_when_removed = max(max_distance_when_removed, manhattan(p1, p2))
            min_max_distance = min(min_max_distance, max_distance_when_removed)
        
        return min_max_distance
