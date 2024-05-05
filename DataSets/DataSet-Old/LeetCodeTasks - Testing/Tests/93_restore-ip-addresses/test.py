# test_solution.py
import unittest
from solution import Solution

class TestSolution(unittest.TestCase):
    def setUp(self):
        self.sol = Solution()

    def test_example_1(self):
        s = "25525511135"
        expected = {"255.255.11.135", "255.255.111.35"}
        self.assertEqual(set(self.sol.restoreIpAddresses(s)), expected)

    def test_example_2(self):
        s = "0000"
        expected = {"0.0.0.0"}
        self.assertEqual(set(self.sol.restoreIpAddresses(s)), expected)

    def test_example_3(self):
        s = "101023"
        expected = {"1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"}
        self.assertEqual(set(self.sol.restoreIpAddresses(s)), expected)

    def test_invalid_long_number(self):
        s = "11111111111111111111"
        expected = set()
        self.assertEqual(set(self.sol.restoreIpAddresses(s)), expected)

    def test_no_possible_addresses(self):
        s = "123"
        expected = set()
        self.assertEqual(set(self.sol.restoreIpAddresses(s)), expected)

    def test_mixed_length_addresses(self):
        s = "1234567890"
        expected = {
            "123.45.67.890", "123.45.678.90", "123.456.7.890", "123.456.78.90",
            "12.34.56.789", "12.34.567.89", "12.345.67.890", "12.345.678.90",
            "1.234.567.890", "1.234.56.789", "1.234.567.89", "1.23.456.7890"
        }
        # Only valid IP addresses will remain after parsing
        valid_expected = {ip for ip in expected if all(
            0 <= int(part) <= 255 and (part == "0" or part[0] != "0")
            for part in ip.split(".")
        )}
        self.assertEqual(set(self.sol.restoreIpAddresses(s)), valid_expected)

if __name__ == "__main__":
    unittest.main()
