import unittest
from solution import Solution

class TestLargestSquareArea(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_example1(self):
        bottomLeft = [[1, 1], [2, 2], [3, 1]]
        topRight = [[3, 3], [4, 4], [6, 6]]
        self.assertEqual(self.solution.largestSquareArea(bottomLeft, topRight), 1)

    def test_example2(self):
        bottomLeft = [[1, 1], [2, 2], [1, 2]]
        topRight = [[3, 3], [4, 4], [3, 4]]
        self.assertEqual(self.solution.largestSquareArea(bottomLeft, topRight), 1)

    def test_example3(self):
        bottomLeft = [[1, 1], [3, 3], [3, 1]]
        topRight = [[2, 2], [4, 4], [4, 2]]
        self.assertEqual(self.solution.largestSquareArea(bottomLeft, topRight), 0)

    def test_no_intersection(self):
        bottomLeft = [[1, 1], [5, 5]]
        topRight = [[2, 2], [6, 6]]
        self.assertEqual(self.solution.largestSquareArea(bottomLeft, topRight), 0)

    def test_full_overlap(self):
        bottomLeft = [[1, 1], [1, 1]]
        topRight = [[5, 5], [5, 5]]
        self.assertEqual(self.solution.largestSquareArea(bottomLeft, topRight), 16)

    def test_partial_overlap(self):
        bottomLeft = [[1, 1], [3, 3]]
        topRight = [[5, 5], [7, 7]]
        self.assertEqual(self.solution.largestSquareArea(bottomLeft, topRight), 4)

if __name__ == '__main__':
    unittest.main()
