import unittest
from solution import Solution

class TestSolution(unittest.TestCase):
    def test_subsetsWithDup(self):
        sol = Solution()
        # Test case 1
        nums = [1, 2, 2]
        expected_output = [[], [1], [1, 2], [1, 2, 2], [2], [2, 2]]
        result = sol.subsetsWithDup(nums)
        self.assertEqual(sorted(map(sorted, result)), sorted(map(sorted, expected_output)))
        
        # Test case 2
        nums = [0]
        expected_output = [[], [0]]
        result = sol.subsetsWithDup(nums)
        self.assertEqual(sorted(map(sorted, result)), sorted(map(sorted, expected_output)))
        
        # Test case 3: Single duplicate element
        nums = [2, 2]
        expected_output = [[], [2], [2, 2]]
        result = sol.subsetsWithDup(nums)
        self.assertEqual(sorted(map(sorted, result)), sorted(map(sorted, expected_output)))
        
        # Test case 4: Empty input
        nums = []
        expected_output = [[]]
        result = sol.subsetsWithDup(nums)
        self.assertEqual(sorted(map(sorted, result)), sorted(map(sorted, expected_output)))
        
        # Test case 5: Larger set with duplicates
        nums = [1, 2, 2, 3]
        expected_output = [[], [1], [1, 2], [1, 2, 2], [1, 2, 2, 3], [1, 2, 3], [1, 3], [2], [2, 2], [2, 2, 3], [2, 3], [3]]
        result = sol.subsetsWithDup(nums)
        self.assertEqual(sorted(map(sorted, result)), sorted(map(sorted, expected_output)))
        
if __name__ == '__main__':
    unittest.main()
