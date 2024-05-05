import unittest
from solution import Solution

class TestSolution(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_example1(self):
        self.assertEqual(self.solution.strStr("sadbutsad", "sad"), 0)

    def test_example2(self):
        self.assertEqual(self.solution.strStr("leetcode", "leeto"), -1)

    def test_single_char_haystack(self):
        self.assertEqual(self.solution.strStr("a", "a"), 0)
        self.assertEqual(self.solution.strStr("a", "b"), -1)

    def test_single_char_needle(self):
        self.assertEqual(self.solution.strStr("abc", "a"), 0)
        self.assertEqual(self.solution.strStr("abc", "b"), 1)
        self.assertEqual(self.solution.strStr("abc", "c"), 2)
        self.assertEqual(self.solution.strStr("abc", "d"), -1)

    def test_empty_needle(self):
        self.assertEqual(self.solution.strStr("abc", ""), 0)
        self.assertEqual(self.solution.strStr("", ""), 0)

    def test_empty_haystack(self):
        self.assertEqual(self.solution.strStr("", "a"), -1)

    def test_needle_larger_than_haystack(self):
        self.assertEqual(self.solution.strStr("abc", "abcd"), -1)

    def test_multiple_occurrences(self):
        self.assertEqual(self.solution.strStr("abababab", "abab"), 0)
        self.assertEqual(self.solution.strStr("aaaabaaaaa", "ba"), 4)

if __name__ == '__main__':
    unittest.main()
