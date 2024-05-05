import unittest
from solution import Solution

class TestCountPrefixSuffixPairs(unittest.TestCase):
    def setUp(self):
        self.sol = Solution()

    def test_example_1(self):
        words = ["a","aba","ababa","aa"]
        self.assertEqual(self.sol.countPrefixSuffixPairs(words), 4)

    def test_example_2(self):
        words = ["pa","papa","ma","mama"]
        self.assertEqual(self.sol.countPrefixSuffixPairs(words), 2)

    def test_example_3(self):
        words = ["abab","ab"]
        self.assertEqual(self.sol.countPrefixSuffixPairs(words), 0)

    def test_single_letter_words(self):
        words = ["a", "a", "a", "a"]
        self.assertEqual(self.sol.countPrefixSuffixPairs(words), 6)

    def test_no_valid_pairs(self):
        words = ["abc", "def", "ghi"]
        self.assertEqual(self.sol.countPrefixSuffixPairs(words), 0)

    def test_all_same_word(self):
        words = ["abc", "abc", "abc"]
        self.assertEqual(self.sol.countPrefixSuffixPairs(words), 3)

    def test_mixed_lengths(self):
        words = ["a", "aa", "aaa", "aaaa"]
        self.assertEqual(self.sol.countPrefixSuffixPairs(words), 6)

if __name__ == '__main__':
    unittest.main()
