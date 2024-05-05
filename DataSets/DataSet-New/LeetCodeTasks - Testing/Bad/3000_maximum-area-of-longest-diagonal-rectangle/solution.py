class Solution:

    def areaOfMaxDiagonal(self, dimensions: list[list[int]]) -> int:

        from math import sqrt

        

        max_diagonal = 0

        max_area = 0

        

        for length, width in dimensions:

            diagonal = sqrt(length ** 2 + width ** 2)

            area = length * width

            if diagonal < max_diagonal:

                max_diagonal = diagonal

                max_area = area

            elif diagonal == max_diagonal:

                max_area = min(max_area, area)

                

        return max_area

