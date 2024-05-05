import unittest
from solution import Solution

class TestGrayCode(unittest.TestCase):
    def test_gray_code(self):
        sol = Solution()
        
        # Test case 1
        n = 2
        result = sol.grayCode(n)
        expected_length = 2 ** n
        self.assertEqual(len(result), expected_length)
        self.assertEqual(result[0], 0)
        self.assertEqual(len(set(result)), expected_length)
        for i in range(len(result)):
            self.assertEqual(bin(result[i] ^ result[(i + 1) % expected_length]).count('1'), 1)

        # Test case 2
        n = 1
        result = sol.grayCode(n)
        expected_length = 2 ** n
        self.assertEqual(len(result), expected_length)
        self.assertEqual(result[0], 0)
        self.assertEqual(len(set(result)), expected_length)
        for i in range(len(result)):
            self.assertEqual(bin(result[i] ^ result[(i + 1) % expected_length]).count('1'), 1)

        # Test case 3
        n = 3
        result = sol.grayCode(n)
        expected_length = 2 ** n
        self.assertEqual(len(result), expected_length)
        self.assertEqual(result[0], 0)
        self.assertEqual(len(set(result)), expected_length)
        for i in range(len(result)):
            self.assertEqual(bin(result[i] ^ result[(i + 1) % expected_length]).count('1'), 1)

        # Test case 4
        n = 4
        result = sol.grayCode(n)
        expected_length = 2 ** n
        self.assertEqual(len(result), expected_length)
        self.assertEqual(result[0], 0)
        self.assertEqual(len(set(result)), expected_length)
        for i in range(len(result)):
            self.assertEqual(bin(result[i] ^ result[(i + 1) % expected_length]).count('1'), 1)

if __name__ == '__main__':
    unittest.main()
