import unittest
from solution import Solution

class TestMinimumLevels(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_case_1(self):
        possible = [1, 0, 1, 0]
        expected = 1
        result = self.solution.minimumLevels(possible)
        self.assertEqual(result, expected)

    def test_case_2(self):
        possible = [1, 1, 1, 1, 1]
        expected = 3
        result = self.solution.minimumLevels(possible)
        self.assertEqual(result, expected)

    def test_case_3(self):
        possible = [0, 0]
        expected = -1
        result = self.solution.minimumLevels(possible)
        self.assertEqual(result, expected)

    def test_case_4(self):
        possible = [1, 0, 0, 1, 0, 1, 1]
        expected = 2
        result = self.solution.minimumLevels(possible)
        self.assertEqual(result, expected)

    def test_case_5(self):
        possible = [1, 1, 0, 1, 0, 0, 1]
        expected = 3
        result = self.solution.minimumLevels(possible)
        self.assertEqual(result, expected)

    def test_case_6(self):
        possible = [1, 0, 1]
        expected = 2
        result = self.solution.minimumLevels(possible)
        self.assertEqual(result, expected)

    def test_case_7(self):
        possible = [1, 1]
        expected = 1
        result = self.solution.minimumLevels(possible)
        self.assertEqual(result, expected)

if __name__ == "__main__":
    unittest.main()
