import unittest
from solution import Solution

class TestMaximumPrimeDifference(unittest.TestCase):
    
    def setUp(self):
        self.solution = Solution()
    
    def test_example1(self):
        nums = [4, 2, 9, 5, 3]
        expected_output = 3
        self.assertEqual(self.solution.maximumPrimeDifference(nums), expected_output)
    
    def test_example2(self):
        nums = [4, 8, 2, 8]
        expected_output = 0
        self.assertEqual(self.solution.maximumPrimeDifference(nums), expected_output)
    
    def test_all_primes(self):
        nums = [2, 3, 5, 7, 11, 13, 17, 19]
        expected_output = 7
        self.assertEqual(self.solution.maximumPrimeDifference(nums), expected_output)
    
    def test_no_primes(self):
        nums = [1, 4, 6, 8, 9, 10]
        expected_output = 0
        self.assertEqual(self.solution.maximumPrimeDifference(nums), expected_output)
    
    def test_multiple_primes_same_value(self):
        nums = [5, 1, 5, 3, 5]
        expected_output = 4
        self.assertEqual(self.solution.maximumPrimeDifference(nums), expected_output)

    def test_large_input(self):
        nums = [4, 2] * 150000 + [5]
        expected_output = 300000
        self.assertEqual(self.solution.maximumPrimeDifference(nums), expected_output)

if __name__ == '__main__':
    unittest.main()
