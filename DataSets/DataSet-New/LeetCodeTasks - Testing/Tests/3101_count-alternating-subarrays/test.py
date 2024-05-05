import unittest
from solution import Solution

class TestCountAlternatingSubarrays(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_example1(self):
        self.assertEqual(self.solution.countAlternatingSubarrays([0, 1, 1, 1]), 5)

    def test_example2(self):
        self.assertEqual(self.solution.countAlternatingSubarrays([1, 0, 1, 0]), 10)

    def test_single_element(self):
        self.assertEqual(self.solution.countAlternatingSubarrays([0]), 1)
        self.assertEqual(self.solution.countAlternatingSubarrays([1]), 1)

    def test_two_elements(self):
        self.assertEqual(self.solution.countAlternatingSubarrays([0, 1]), 3)
        self.assertEqual(self.solution.countAlternatingSubarrays([1, 0]), 3)
        self.assertEqual(self.solution.countAlternatingSubarrays([1, 1]), 2)
        self.assertEqual(self.solution.countAlternatingSubarrays([0, 0]), 2)

    def test_longer_alternating(self):
        self.assertEqual(self.solution.countAlternatingSubarrays([1, 0, 1, 0, 1]), 15)

    def test_longer_non_alternating(self):
        self.assertEqual(self.solution.countAlternatingSubarrays([1, 1, 1, 1, 1]), 5)

    def test_mixed(self):
        self.assertEqual(self.solution.countAlternatingSubarrays([1, 0, 0, 1, 0, 1]), 13)

if __name__ == "__main__":
    unittest.main()
