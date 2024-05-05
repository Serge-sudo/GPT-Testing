import unittest
from solution import Solution

class TestMaximalRectangle(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_example_1(self):
        matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
        self.assertEqual(self.solution.maximalRectangle(matrix), 6)

    def test_example_2(self):
        matrix = [["0"]]
        self.assertEqual(self.solution.maximalRectangle(matrix), 0)

    def test_example_3(self):
        matrix = [["1"]]
        self.assertEqual(self.solution.maximalRectangle(matrix), 1)

    def test_all_zeros(self):
        matrix = [["0","0","0"],["0","0","0"],["0","0","0"]]
        self.assertEqual(self.solution.maximalRectangle(matrix), 0)

    def test_all_ones(self):
        matrix = [["1","1","1"],["1","1","1"],["1","1","1"]]
        self.assertEqual(self.solution.maximalRectangle(matrix), 9)

    def test_mixed_matrix(self):
        matrix = [["1","1","0","1"],["1","0","1","0"],["0","1","1","1"],["1","1","1","0"]]
        self.assertEqual(self.solution.maximalRectangle(matrix), 4)

if __name__ == "__main__":
    unittest.main()
