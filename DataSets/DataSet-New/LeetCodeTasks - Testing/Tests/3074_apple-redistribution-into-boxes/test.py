import unittest
from solution import Solution

class TestSolution(unittest.TestCase):
    def setUp(self):
        self.sol = Solution()
    
    def test_example_1(self):
        apple = [1, 3, 2]
        capacity = [4, 3, 1, 5, 2]
        self.assertEqual(self.sol.minimumBoxes(apple, capacity), 2)
    
    def test_example_2(self):
        apple = [5, 5, 5]
        capacity = [2, 4, 2, 7]
        self.assertEqual(self.sol.minimumBoxes(apple, capacity), 4)
    
    def test_small_boxes_large_apples(self):
        apple = [10, 20, 30]
        capacity = [15, 15, 15, 15, 15, 15]
        self.assertEqual(self.sol.minimumBoxes(apple, capacity), 4)
    
    def test_large_boxes_small_apples(self):
        apple = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
        capacity = [5, 5]
        self.assertEqual(self.sol.minimumBoxes(apple, capacity), 2)
    
    def test_single_pack(self):
        apple = [50]
        capacity = [10, 10, 10, 10, 10, 10]
        self.assertEqual(self.sol.minimumBoxes(apple, capacity), 5)
    
    def test_single_box(self):
        apple = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
        capacity = [10]
        self.assertEqual(self.sol.minimumBoxes(apple, capacity), 1)
    
    def test_exact_fit(self):
        apple = [10, 20, 30]
        capacity = [10, 20, 30]
        self.assertEqual(self.sol.minimumBoxes(apple, capacity), 3)
    
    def test_multiple_packs_and_boxes(self):
        apple = [10, 10, 10, 10, 10, 10]
        capacity = [5, 10, 15, 20, 25, 30]
        self.assertEqual(self.sol.minimumBoxes(apple, capacity), 2)
    
if __name__ == '__main__':
    unittest.main()
