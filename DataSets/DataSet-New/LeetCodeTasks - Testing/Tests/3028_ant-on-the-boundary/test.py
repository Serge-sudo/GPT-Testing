import unittest
from solution import Solution

class TestAntMovement(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_example1(self):
        nums = [2, 3, -5]
        expected = 1
        result = self.solution.returnToBoundaryCount(nums)
        self.assertEqual(result, expected)

    def test_example2(self):
        nums = [3, 2, -3, -4]
        expected = 0
        result = self.solution.returnToBoundaryCount(nums)
        self.assertEqual(result, expected)

    def test_boundary_cross(self):
        nums = [5, -5, 5, -5]
        expected = 3
        result = self.solution.returnToBoundaryCount(nums)
        self.assertEqual(result, expected)

    def test_no_return(self):
        nums = [1, 2, 3, 4, 5]
        expected = 0
        result = self.solution.returnToBoundaryCount(nums)
        self.assertEqual(result, expected)

    def test_multiple_returns(self):
        nums = [1, -1, 1, -1, 1, -1]
        expected = 5
        result = self.solution.returnToBoundaryCount(nums)
        self.assertEqual(result, expected)

    def test_large_movements(self):
        nums = [10, -10, 10, -10, 10, -10]
        expected = 5
        result = self.solution.returnToBoundaryCount(nums)
        self.assertEqual(result, expected)

    def test_negative_movements(self):
        nums = [-1, -1, -1, -1, 4]
        expected = 0
        result = self.solution.returnToBoundaryCount(nums)
        self.assertEqual(result, expected)

    def test_alternating_movements(self):
        nums = [2, -2, 2, -2, 2, -2, 2, -2]
        expected = 7
        result = self.solution.returnToBoundaryCount(nums)
        self.assertEqual(result, expected)

if __name__ == "__main__":
    unittest.main()
