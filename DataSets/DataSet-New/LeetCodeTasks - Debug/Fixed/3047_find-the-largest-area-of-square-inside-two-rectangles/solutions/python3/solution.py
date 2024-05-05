class Solution:
    def largestSquareArea(self, bottomLeft: list[list[int]], topRight: list[list[int]]) -> int:
        n = len(bottomLeft)
        max_square_area = 0

        for i in range(n):
            for j in range(i + 1, n):
                # Calculate the intersection of rectangles i and j
                inter_bl_x = max(bottomLeft[i][0], bottomLeft[j][0])
                inter_bl_y = max(bottomLeft[i][1], bottomLeft[j][1])
                inter_tr_x = min(topRight[i][0], topRight[j][0])
                inter_tr_y = min(topRight[i][1], topRight[j][1])

                # Check if the intersection is valid (non-empty)
                if inter_bl_x < inter_tr_x and inter_bl_y < inter_tr_y:
                    # Calculate the possible maximum side of a square in this intersection
                    max_side = min(inter_tr_x - inter_bl_x, inter_tr_y - inter_bl_y)
                    max_square_area = max(max_square_area, max_side * max_side)

        return max_square_area
