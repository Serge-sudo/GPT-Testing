import unittest
from solution import Solution

class TestMinRectanglesToCoverPoints(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_example1(self):
        points = [[2,1],[1,0],[1,4],[1,8],[3,5],[4,6]]
        w = 1
        expected = 2
        result = self.solution.minRectanglesToCoverPoints(points, w)
        self.assertEqual(result, expected)

    def test_example2(self):
        points = [[0,0],[1,1],[2,2],[3,3],[4,4],[5,5],[6,6]]
        w = 2
        expected = 3
        result = self.solution.minRectanglesToCoverPoints(points, w)
        self.assertEqual(result, expected)

    def test_example3(self):
        points = [[2,3],[1,2]]
        w = 0
        expected = 2
        result = self.solution.minRectanglesToCoverPoints(points, w)
        self.assertEqual(result, expected)

    def test_single_point(self):
        points = [[0,0]]
        w = 1
        expected = 1
        result = self.solution.minRectanglesToCoverPoints(points, w)
        self.assertEqual(result, expected)

    def test_large_w(self):
        points = [[1,1],[2,2],[3,3],[4,4],[5,5]]
        w = 10
        expected = 1
        result = self.solution.minRectanglesToCoverPoints(points, w)
        self.assertEqual(result, expected)

    def test_no_overlap(self):
        points = [[0,0],[10,10],[20,20],[30,30]]
        w = 5
        expected = 4
        result = self.solution.minRectanglesToCoverPoints(points, w)
        self.assertEqual(result, expected)

    def test_partial_overlap(self):
        points = [[0,0],[1,1],[4,4],[5,5]]
        w = 2
        expected = 2
        result = self.solution.minRectanglesToCoverPoints(points, w)
        self.assertEqual(result, expected)

    def test_all_points_same_x(self):
        points = [[3,1],[3,2],[3,3],[3,4]]
        w = 0
        expected = 4
        result = self.solution.minRectanglesToCoverPoints(points, w)
        self.assertEqual(result, expected)

if __name__ == "__main__":
    unittest.main()
