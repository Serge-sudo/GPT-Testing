import unittest
from solution import Solution

class TestSolution(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_example_1(self):
        self.assertEqual(self.solution.countKeyChanges("aAbBcC"), 2)

    def test_example_2(self):
        self.assertEqual(self.solution.countKeyChanges("AaAaAaaA"), 0)

    def test_single_char(self):
        self.assertEqual(self.solution.countKeyChanges("a"), 0)

    def test_alternating_chars(self):
        self.assertEqual(self.solution.countKeyChanges("aAaAaA"), 0)
        self.assertEqual(self.solution.countKeyChanges("abABabAB"), 4)

    def test_no_change(self):
        self.assertEqual(self.solution.countKeyChanges("BBBB"), 0)
        self.assertEqual(self.solution.countKeyChanges("aaaa"), 0)

    def test_all_changes(self):
        self.assertEqual(self.solution.countKeyChanges("aBcDeFgH"), 7)

    def test_mixed_case(self):
        self.assertEqual(self.solution.countKeyChanges("AbCdEfGhIj"), 9)

if __name__ == "__main__":
    unittest.main()
