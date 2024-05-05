# test_solution.py

import unittest
from solution import Solution

class TestFullJustify(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_example_1(self):
        words = ["This", "is", "an", "example", "of", "text", "justification."]
        maxWidth = 16
        expected_output = [
            "This    is    an",
            "example of text",
            "justification.  "
        ]
        self.assertEqual(self.solution.fullJustify(words, maxWidth), expected_output)

    def test_example_2(self):
        words = ["What","must","be","acknowledgment","shall","be"]
        maxWidth = 16
        expected_output = [
            "What   must   be",
            "acknowledgment  ",
            "shall be        "
        ]
        self.assertEqual(self.solution.fullJustify(words, maxWidth), expected_output)

    def test_example_3(self):
        words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]
        maxWidth = 20
        expected_output = [
            "Science  is  what we",
            "understand      well",
            "enough to explain to",
            "a computer. Art is",
            "everything else we",
            "do                "
        ]
        self.assertEqual(self.solution.fullJustify(words, maxWidth), expected_output)

    def test_single_word(self):
        words = ["word"]
        maxWidth = 10
        expected_output = ["word      "]
        self.assertEqual(self.solution.fullJustify(words, maxWidth), expected_output)

    def test_longer_words(self):
        words = ["longer", "words", "example"]
        maxWidth = 18
        expected_output = [
            "longer words      ",
            "example           "
        ]
        self.assertEqual(self.solution.fullJustify(words, maxWidth), expected_output)

    def test_all_same_length(self):
        words = ["abc", "def", "ghi", "jkl"]
        maxWidth = 9
        expected_output = [
            "abc def ghi",
            "jkl        "
        ]
        self.assertEqual(self.solution.fullJustify(words, maxWidth), expected_output)

if __name__ == "__main__":
    unittest.main()
