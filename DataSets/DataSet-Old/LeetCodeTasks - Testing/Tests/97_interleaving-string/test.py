import unittest
from solution import Solution

class TestIsInterleave(unittest.TestCase):
    def test_example_1(self):
        s1 = "aabcc"
        s2 = "dbbca"
        s3 = "aadbbcbcac"
        self.assertTrue(Solution().isInterleave(s1, s2, s3))

    def test_example_2(self):
        s1 = "aabcc"
        s2 = "dbbca"
        s3 = "aadbbbaccc"
        self.assertFalse(Solution().isInterleave(s1, s2, s3))

    def test_example_3(self):
        s1 = ""
        s2 = ""
        s3 = ""
        self.assertTrue(Solution().isInterleave(s1, s2, s3))

if __name__ == "__main__":
    unittest.main()
