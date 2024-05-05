import unittest
from solution import Solution

class TestWildcardMatching(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_case_1(self):
        self.assertFalse(self.solution.isMatch("aa", "a"))

    def test_case_2(self):
        self.assertTrue(self.solution.isMatch("aa", "*"))

    def test_case_3(self):
        self.assertFalse(self.solution.isMatch("cb", "?a"))

    def test_case_4(self):
        self.assertTrue(self.solution.isMatch("abcde", "*e"))

    def test_case_5(self):
        self.assertTrue(self.solution.isMatch("abcdefg", "a?c*fg"))

    def test_case_6(self):
        self.assertTrue(self.solution.isMatch("x", "?"))

    def test_case_7(self):
        self.assertFalse(self.solution.isMatch("x", "*y"))

    def test_case_8(self):
        self.assertTrue(self.solution.isMatch("", "*"))

    def test_case_9(self):
        self.assertFalse(self.solution.isMatch("", "?"))

    def test_case_10(self):
        self.assertTrue(self.solution.isMatch("abcd", "*?d"))

if __name__ == "__main__":
    unittest.main()
