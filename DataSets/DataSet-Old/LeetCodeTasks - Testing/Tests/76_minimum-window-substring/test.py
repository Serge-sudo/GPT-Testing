import unittest
from solution import Solution

class TestMinWindow(unittest.TestCase):
    def setUp(self):
        self.sol = Solution()

    def test_example_1(self):
        self.assertEqual(self.sol.minWindow("ADOBECODEBANC", "ABC"), "BANC")

    def test_example_2(self):
        self.assertEqual(self.sol.minWindow("a", "a"), "a")

    def test_example_3(self):
        self.assertEqual(self.sol.minWindow("a", "aa"), "")

    def test_multiple_occurrences(self):
        self.assertEqual(self.sol.minWindow("ADOBECODEBANCBAB", "AABC"), "BANCBA")

    def test_empty_s(self):
        self.assertEqual(self.sol.minWindow("", "a"), "")

    def test_empty_t(self):
        self.assertEqual(self.sol.minWindow("a", ""), "")

    def test_no_overlap(self):
        self.assertEqual(self.sol.minWindow("abcdef", "xyz"), "")

    def test_exact_match(self):
        self.assertEqual(self.sol.minWindow("abcdef", "abcdef"), "abcdef")

if __name__ == "__main__":
    unittest.main()
