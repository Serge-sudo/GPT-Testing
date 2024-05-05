import unittest
from solution import Solution

class TestRainWaterTrapping(unittest.TestCase):
    def test_example_1(self):
        solution = Solution()
        self.assertEqual(solution.trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]), 6)

    def test_example_2(self):
        solution = Solution()
        self.assertEqual(solution.trap([4, 2, 0, 3, 2, 5]), 9)

    def test_empty(self):
        solution = Solution()
        self.assertEqual(solution.trap([]), 0)

    def test_flat(self):
        solution = Solution()
        self.assertEqual(solution.trap([1, 1, 1, 1]), 0)

    def test_single_peak(self):
        solution = Solution()
        self.assertEqual(solution.trap([0, 5, 0]), 0)

    def test_v_shape(self):
        solution = Solution()
        self.assertEqual(solution.trap([3, 0, 3]), 3)

    def test_large_values(self):
        solution = Solution()
        self.assertEqual(solution.trap([100, 0, 100]), 100)

    def test_long_elevation_map(self):
        solution = Solution()
        height = [2, 1, 0, 2, 3, 4, 0, 3, 0, 1, 0, 4, 0, 3]
        self.assertEqual(solution.trap(height), 21)

if __name__ == '__main__':
    unittest.main()
