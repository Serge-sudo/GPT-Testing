import unittest
from solution import Solution

class TestSearchInsert(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_case_1(self):
        nums = [1, 3, 5, 6]
        target = 5
        expected = 2
        self.assertEqual(self.solution.searchInsert(nums, target), expected)

    def test_case_2(self):
        nums = [1, 3, 5, 6]
        target = 2
        expected = 1
        self.assertEqual(self.solution.searchInsert(nums, target), expected)

    def test_case_3(self):
        nums = [1, 3, 5, 6]
        target = 7
        expected = 4
        self.assertEqual(self.solution.searchInsert(nums, target), expected)

    def test_case_4(self):
        nums = [1, 3, 5, 6]
        target = 0
        expected = 0
        self.assertEqual(self.solution.searchInsert(nums, target), expected)

    def test_case_5(self):
        nums = [1]
        target = 0
        expected = 0
        self.assertEqual(self.solution.searchInsert(nums, target), expected)

    def test_case_6(self):
        nums = [1]
        target = 2
        expected = 1
        self.assertEqual(self.solution.searchInsert(nums, target), expected)

if __name__ == '__main__':
    unittest.main()
