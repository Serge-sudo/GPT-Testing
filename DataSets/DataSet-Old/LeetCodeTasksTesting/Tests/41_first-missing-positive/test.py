import unittest
from solution import Solution

class TestFirstMissingPositive(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_example1(self):
        nums = [1, 2, 0]
        self.assertEqual(self.solution.firstMissingPositive(nums), 3)

    def test_example2(self):
        nums = [3, 4, -1, 1]
        self.assertEqual(self.solution.firstMissingPositive(nums), 2)

    def test_example3(self):
        nums = [7, 8, 9, 11, 12]
        self.assertEqual(self.solution.firstMissingPositive(nums), 1)

    def test_empty_list(self):
        nums = []
        self.assertEqual(self.solution.firstMissingPositive(nums), 1)

    def test_single_positive_number(self):
        nums = [2]
        self.assertEqual(self.solution.firstMissingPositive(nums), 1)

    def test_single_negative_number(self):
        nums = [-1]
        self.assertEqual(self.solution.firstMissingPositive(nums), 1)

    def test_mixed_numbers(self):
        nums = [1, 2, 3, -10, 0, 5, -20]
        self.assertEqual(self.solution.firstMissingPositive(nums), 4)

    def test_repeated_numbers(self):
        nums = [1, 1, 1, 1, 1, 1]
        self.assertEqual(self.solution.firstMissingPositive(nums), 2)

    def test_large_array(self):
        nums = list(range(1, 100001))
        self.assertEqual(self.solution.firstMissingPositive(nums), 100001)

if __name__ == "__main__":
    unittest.main()
