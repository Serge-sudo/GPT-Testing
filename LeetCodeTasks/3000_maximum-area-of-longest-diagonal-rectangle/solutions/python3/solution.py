class Solution:
    def areaOfMaxDiagonal(self, dimensions: list[list[int]]) -> int:
        max_diagonal = 0
        max_area = 0
        
        for length, width in dimensions:
            diagonal = length ** 2 + width ** 2
            area = length * width
            
            if diagonal > max_diagonal or (diagonal == max_diagonal and area > max_area):
                max_diagonal = diagonal
                max_area = area
                
        return max_area
