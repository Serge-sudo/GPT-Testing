import unittest
from solution import Solution

class TestTriangleType(unittest.TestCase):
    
    def setUp(self):
        self.solution = Solution()
        
    def test_equilateral(self):
        self.assertEqual(self.solution.triangleType([3, 3, 3]), "equilateral")
        
    def test_isosceles(self):
        self.assertEqual(self.solution.triangleType([3, 3, 4]), "isosceles")
        self.assertEqual(self.solution.triangleType([4, 3, 3]), "isosceles")
        self.assertEqual(self.solution.triangleType([3, 4, 3]), "isosceles")
        
    def test_scalene(self):
        self.assertEqual(self.solution.triangleType([3, 4, 5]), "scalene")
        self.assertEqual(self.solution.triangleType([5, 7, 10]), "scalene")
        
    def test_none(self):
        self.assertEqual(self.solution.triangleType([1, 1, 2]), "none")
        self.assertEqual(self.solution.triangleType([1, 2, 3]), "none")
        self.assertEqual(self.solution.triangleType([5, 1, 1]), "none")
        
if __name__ == '__main__':
    unittest.main()
