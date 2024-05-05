import unittest
from solution import Solution

class TestClimbStairs(unittest.TestCase):
    def test_example_1(self):
        sol = Solution()
        self.assertEqual(sol.climbStairs(2), 2)

    def test_example_2(self):
        sol = Solution()
        self.assertEqual(sol.climbStairs(3), 3)

    def test_custom_1(self):
        sol = Solution()
        self.assertEqual(sol.climbStairs(1), 1)

    def test_custom_2(self):
        sol = Solution()
        self.assertEqual(sol.climbStairs(4), 5)

    def test_custom_3(self):
        sol = Solution()
        self.assertEqual(sol.climbStairs(5), 8)

if __name__ == '__main__':
    unittest.main()
