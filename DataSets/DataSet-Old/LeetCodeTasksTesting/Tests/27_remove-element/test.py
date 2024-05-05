import unittest
from solution import Solution

class TestRemoveElement(unittest.TestCase):
    def test_example1(self):
        solution = Solution()
        nums = [3, 2, 2, 3]
        val = 3
        expectedNums = [2, 2]
        k = solution.removeElement(nums, val)
        self.assertEqual(k, len(expectedNums))
        self.assertCountEqual(nums[:k], expectedNums)

    def test_example2(self):
        solution = Solution()
        nums = [0, 1, 2, 2, 3, 0, 4, 2]
        val = 2
        expectedNums = [0, 1, 0, 3, 4]
        k = solution.removeElement(nums, val)
        self.assertEqual(k, len(expectedNums))
        self.assertCountEqual(nums[:k], expectedNums)

    def test_no_occurrences(self):
        solution = Solution()
        nums = [1, 2, 3, 4, 5]
        val = 6
        expectedNums = [1, 2, 3, 4, 5]
        k = solution.removeElement(nums, val)
        self.assertEqual(k, len(expectedNums))
        self.assertCountEqual(nums[:k], expectedNums)

    def test_all_occurrences(self):
        solution = Solution()
        nums = [1, 1, 1, 1, 1]
        val = 1
        expectedNums = []
        k = solution.removeElement(nums, val)
        self.assertEqual(k, len(expectedNums))
        self.assertCountEqual(nums[:k], expectedNums)

    def test_mixed_occurrences(self):
        solution = Solution()
        nums = [4, 4, 2, 4, 1, 4, 2]
        val = 4
        expectedNums = [2, 2, 1]
        k = solution.removeElement(nums, val)
        self.assertEqual(k, len(expectedNums))
        self.assertCountEqual(nums[:k], expectedNums)

if __name__ == "__main__":
    unittest.main()
