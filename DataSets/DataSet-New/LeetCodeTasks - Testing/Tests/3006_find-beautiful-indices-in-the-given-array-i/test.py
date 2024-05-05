import unittest
from solution import Solution

class TestBeautifulIndices(unittest.TestCase):
    def setUp(self):
        self.sol = Solution()

    def test_example1(self):
        s = "isawsquirrelnearmysquirrelhouseohmy"
        a = "my"
        b = "squirrel"
        k = 15
        expected = [16, 33]
        result = self.sol.beautifulIndices(s, a, b, k)
        self.assertEqual(result, expected)

    def test_example2(self):
        s = "abcd"
        a = "a"
        b = "a"
        k = 4
        expected = [0]
        result = self.sol.beautifulIndices(s, a, b, k)
        self.assertEqual(result, expected)

    def test_no_beautiful_indices(self):
        s = "abcdefgh"
        a = "xyz"
        b = "uvw"
        k = 2
        expected = []
        result = self.sol.beautifulIndices(s, a, b, k)
        self.assertEqual(result, expected)

    def test_multiple_beautiful_indices(self):
        s = "abacabadabacaba"
        a = "aba"
        b = "aca"
        k = 3
        expected = [0, 7, 9]
        result = self.sol.beautifulIndices(s, a, b, k)
        self.assertEqual(result, expected)

    def test_edge_case(self):
        s = "a" * 100000
        a = "a"
        b = "a"
        k = 1
        expected = list(range(100000))
        result = self.sol.beautifulIndices(s, a, b, k)
        self.assertEqual(result, expected)

if __name__ == '__main__':
    unittest.main()
