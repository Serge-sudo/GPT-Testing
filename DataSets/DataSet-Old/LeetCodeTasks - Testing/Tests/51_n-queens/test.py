import unittest
from solution import Solution

class TestNQueens(unittest.TestCase):
    def setUp(self):
        self.sol = Solution()

    def test_n_1(self):
        result = self.sol.solveNQueens(1)
        expected = [["Q"]]
        self.assertEqual(sorted(result), sorted(expected))

    def test_n_4(self):
        result = self.sol.solveNQueens(4)
        expected = [[".Q..","...Q","Q...","..Q."], ["..Q.","Q...","...Q",".Q.."]]
        self.assertEqual(sorted(result), sorted(expected))

    def test_n_5(self):
        result = self.sol.solveNQueens(5)
        expected = [
            ["Q....", "..Q..", "....Q", ".Q...", "...Q."],
            ["Q....", "...Q.", ".Q...", "....Q", "..Q.."],
            [".Q...", "...Q.", "Q....", "..Q..", "....Q"],
            [".Q...", "....Q", "..Q..", "Q....", "...Q."],
            ["..Q..", "Q....", "...Q.", ".Q...", "....Q"],
            ["..Q..", "....Q", ".Q...", "...Q.", "Q...."],
            ["...Q.", "Q....", "..Q..", "....Q", ".Q..."],
            ["...Q.", ".Q...", "....Q", "..Q..", "Q...."],
            ["....Q", ".Q...", "...Q.", "Q....", "..Q.."],
            ["....Q", "..Q..", "Q....", "...Q.", ".Q..."]
        ]
        self.assertEqual(sorted(result), sorted(expected))

    def test_n_6(self):
        result = self.sol.solveNQueens(6)
        expected = [
            ["Q.....", "..Q...", "....Q.", ".Q....", "...Q..", ".....Q"],
            ["Q.....", "...Q..", ".....Q", ".Q....", "....Q.", "..Q..."],
            [".Q....", "...Q..", "Q.....", ".....Q", "..Q...", "....Q."],
            [".Q....", "....Q.", "..Q...", ".....Q", "Q.....", "...Q.."],
            ["..Q...", "Q.....", "....Q.", ".Q....", ".....Q", "...Q.."],
            ["..Q...", ".....Q", ".Q....", "...Q..", "Q.....", "....Q."],
            ["...Q..", "Q.....", "..Q...", ".....Q", ".Q....", "....Q."],
            ["...Q..", ".....Q", ".Q....", "....Q.", "..Q...", "Q....."],
            ["....Q.", ".Q....", "...Q..", "Q.....", "..Q...", ".....Q"],
            ["....Q.", "..Q...", "Q.....", "...Q..", ".....Q", ".Q...."],
            [".....Q", ".Q....", "...Q..", "Q.....", "....Q.", "..Q..."],
            [".....Q", "..Q...", "....Q.", ".Q....", "...Q..", "Q....."]
        ]
        self.assertEqual(sorted(result), sorted(expected))

    def test_n_8(self):
        result = self.sol.solveNQueens(8)
        self.assertEqual(len(result), 92)

if __name__ == '__main__':
    unittest.main()
