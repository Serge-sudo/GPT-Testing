import unittest
from solution import Solution

class TestNQueens(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_case_1(self):
        self.assertEqual(self.solution.totalNQueens(1), 1)

    def test_case_2(self):
        self.assertEqual(self.solution.totalNQueens(2), 0)

    def test_case_3(self):
        self.assertEqual(self.solution.totalNQueens(3), 0)

    def test_case_4(self):
        self.assertEqual(self.solution.totalNQueens(4), 2)

    def test_case_5(self):
        self.assertEqual(self.solution.totalNQueens(5), 10)

    def test_case_6(self):
        self.assertEqual(self.solution.totalNQueens(6), 4)

    def test_case_7(self):
        self.assertEqual(self.solution.totalNQueens(7), 40)

    def test_case_8(self):
        self.assertEqual(self.solution.totalNQueens(8), 92)

    def test_case_9(self):
        self.assertEqual(self.solution.totalNQueens(9), 352)

if __name__ == '__main__':
    unittest.main()
