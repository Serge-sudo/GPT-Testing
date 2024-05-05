import unittest
from solution import Solution  # Importing the solution class

class TestSolution(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()
    
    def test_example_1(self):
        self.assertEqual(self.solution.areaOfMaxDiagonal([[9, 3], [8, 6]]), 48)

    def test_example_2(self):
        self.assertEqual(self.solution.areaOfMaxDiagonal([[3, 4], [4, 3]]), 12)

    def test_single_rectangle(self):
        self.assertEqual(self.solution.areaOfMaxDiagonal([[5, 5]]), 25)

    def test_same_diagonal_different_area(self):
        self.assertEqual(self.solution.areaOfMaxDiagonal([[10, 10], [14, 2]]), 100)

    def test_same_area_different_diagonal(self):
        self.assertEqual(self.solution.areaOfMaxDiagonal([[6, 7], [7, 6]]), 42)

    def test_maximum_boundaries(self):
        self.assertEqual(self.solution.areaOfMaxDiagonal([[100, 100]] * 100), 10000)

    def test_minimum_boundaries(self):
        self.assertEqual(self.solution.areaOfMaxDiagonal([[1, 1]] * 100), 1)

if __name__ == "__main__":
    unittest.main()
