# test_solution.py

import unittest
from solution import Solution

class TestSolution(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_plus_one_example1(self):
        digits = [1, 2, 3]
        expected = [1, 2, 4]
        self.assertEqual(self.solution.plusOne(digits), expected)

    def test_plus_one_example2(self):
        digits = [4, 3, 2, 1]
        expected = [4, 3, 2, 2]
        self.assertEqual(self.solution.plusOne(digits), expected)

    def test_plus_one_example3(self):
        digits = [9]
        expected = [1, 0]
        self.assertEqual(self.solution.plusOne(digits), expected)

    def test_plus_one_leading_carry(self):
        digits = [9, 9, 9]
        expected = [1, 0, 0, 0]
        self.assertEqual(self.solution.plusOne(digits), expected)

    def test_plus_one_no_carry(self):
        digits = [1, 2, 9]
        expected = [1, 3, 0]
        self.assertEqual(self.solution.plusOne(digits), expected)

    def test_plus_one_single_zero(self):
        digits = [0]
        expected = [1]
        self.assertEqual(self.solution.plusOne(digits), expected)

if __name__ == '__main__':
    unittest.main()
