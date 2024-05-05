import unittest
from solution import Solution

class TestGetPermutation(unittest.TestCase):
    def setUp(self):
        self.sol = Solution()

    def test_case_1(self):
        self.assertEqual(self.sol.getPermutation(3, 3), "213")

    def test_case_2(self):
        self.assertEqual(self.sol.getPermutation(4, 9), "2314")

    def test_case_3(self):
        self.assertEqual(self.sol.getPermutation(3, 1), "123")

    def test_case_4(self):
        self.assertEqual(self.sol.getPermutation(5, 16), "24135")

    def test_case_5(self):
        self.assertEqual(self.sol.getPermutation(6, 400), "341652")

    def test_case_6(self):
        self.assertEqual(self.sol.getPermutation(1, 1), "1")

if __name__ == "__main__":
    unittest.main()
