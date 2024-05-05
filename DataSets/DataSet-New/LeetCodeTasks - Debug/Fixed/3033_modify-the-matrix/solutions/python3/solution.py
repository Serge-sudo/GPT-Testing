from typing import List

class Solution:

    def modifiedMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        m, n = len(matrix), len(matrix[0])

        # Find the maximum values for each column where replacement is needed
        max_in_column = [max(matrix[i][j] for i in range(m) if matrix[i][j] != -1) for j in range(n)]

        # Create a new matrix where -1s are replaced by the max value of their column
        answer = [[max_in_column[j] if matrix[i][j] == -1 else matrix[i][j] for j in range(n)] for i in range(m)]

        return answer
