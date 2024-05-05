import unittest
from solution import Solution

class TestSolution(unittest.TestCase):
    def setUp(self):
        self.sol = Solution()

    def test_mySqrt(self):
        test_cases = [
            (4, 2),
            (8, 2),
            (0, 0),
            (1, 1),
            (9, 3),
            (16, 4),
            (15, 3),
            (2147395599, 46339),
            (2, 1)
        ]
        for x, expected in test_cases:
            with self.subTest(x=x):
                self.assertEqual(self.sol.mySqrt(x), expected)

if __name__ == "__main__":
    unittest.main()
