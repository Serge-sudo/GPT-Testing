import unittest
from solution import Solution

class TestSolution(unittest.TestCase):
    def test_example_1(self):
        sol = Solution()
        matrix = [[1,2,-1],[4,-1,6],[7,8,9]]
        expected_output = [[1,2,9],[4,8,6],[7,8,9]]
        self.assertEqual(sol.modifiedMatrix(matrix), expected_output)

    def test_example_2(self):
        sol = Solution()
        matrix = [[3,-1],[5,2]]
        expected_output = [[3,2],[5,2]]
        self.assertEqual(sol.modifiedMatrix(matrix), expected_output)

    def test_no_negative_1(self):
        sol = Solution()
        matrix = [[1,2,3],[4,5,6],[7,8,9]]
        expected_output = [[1,2,3],[4,5,6],[7,8,9]]
        self.assertEqual(sol.modifiedMatrix(matrix), expected_output)

    def test_all_negative_1(self):
        sol = Solution()
        matrix = [[-1,-1,-1],[-1,-1,-1],[-1,-1,-1]]
        expected_output = [[-1,-1,-1],[-1,-1,-1],[-1,-1,-1]]
        self.assertEqual(sol.modifiedMatrix(matrix), expected_output)

    def test_various_cases(self):
        sol = Solution()
        matrix = [[-1,0,1],[-1,5,6],[3,4,-1]]
        expected_output = [[3,0,6],[3,5,6],[3,4,6]]
        self.assertEqual(sol.modifiedMatrix(matrix), expected_output)
        
        matrix = [[10,-1,20],[-1,15,25],[30,35,-1]]
        expected_output = [[10,35,20],[30,15,25],[30,35,25]]
        self.assertEqual(sol.modifiedMatrix(matrix), expected_output)
        
if __name__ == '__main__':
    unittest.main()
