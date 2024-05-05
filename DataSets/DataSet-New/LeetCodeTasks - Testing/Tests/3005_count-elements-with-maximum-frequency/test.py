import unittest
from solution import Solution

class TestMaxFrequencyElements(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_examples(self):
        # Example 1
        self.assertEqual(self.solution.maxFrequencyElements([1,2,2,3,1,4]), 4)
        
        # Example 2
        self.assertEqual(self.solution.maxFrequencyElements([1,2,3,4,5]), 5)

    def test_edge_cases(self):
        # All elements are the same
        self.assertEqual(self.solution.maxFrequencyElements([7,7,7,7]), 4)
        
        # One element
        self.assertEqual(self.solution.maxFrequencyElements([10]), 1)

    def test_large_input(self):
        # Large input case with various repeating numbers
        nums = [1]*30 + [2]*30 + [3]*40
        self.assertEqual(self.solution.maxFrequencyElements(nums), 40)

        # Each number appears exactly once, large range
        nums = list(range(1, 101))
        self.assertEqual(self.solution.maxFrequencyElements(nums), 100)

if __name__ == "__main__":
    unittest.main()
