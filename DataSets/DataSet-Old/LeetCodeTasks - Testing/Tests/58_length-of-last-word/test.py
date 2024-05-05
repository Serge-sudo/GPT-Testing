import unittest
from solution import Solution

class TestSolution(unittest.TestCase):
    def test_length_of_last_word(self):
        solution = Solution()
        # Example 1
        self.assertEqual(solution.lengthOfLastWord("Hello World"), 5)
        # Example 2
        self.assertEqual(solution.lengthOfLastWord("   fly me   to   the moon  "), 4)
        # Example 3
        self.assertEqual(solution.lengthOfLastWord("luffy is still joyboy"), 6)
        # Additional tests
        self.assertEqual(solution.lengthOfLastWord("a"), 1)
        self.assertEqual(solution.lengthOfLastWord("    a    "), 1)
        self.assertEqual(solution.lengthOfLastWord("word"), 4)
        self.assertEqual(solution.lengthOfLastWord("end of sentence"), 8)
        self.assertEqual(solution.lengthOfLastWord("multiple   spaces     "), 7)

if __name__ == '__main__':
    unittest.main()
