# test_solution.py

import unittest
from solution import Solution, TreeNode

class TestSolution(unittest.TestCase):
    def setUp(self):
        self.sol = Solution()

    def test_example_1(self):
        # Example 1: [2,1,3]
        root = TreeNode(2, TreeNode(1), TreeNode(3))
        self.assertTrue(self.sol.isValidBST(root))

    def test_example_2(self):
        # Example 2: [5,1,4,null,null,3,6]
        root = TreeNode(5, TreeNode(1), TreeNode(4, TreeNode(3), TreeNode(6)))
        self.assertFalse(self.sol.isValidBST(root))

    def test_single_node(self):
        # Test case: Single node
        root = TreeNode(0)
        self.assertTrue(self.sol.isValidBST(root))

    def test_left_heavy(self):
        # Test case: Left-heavy BST
        root = TreeNode(10, TreeNode(5, TreeNode(2), TreeNode(8)), None)
        self.assertTrue(self.sol.isValidBST(root))

    def test_right_heavy(self):
        # Test case: Right-heavy BST
        root = TreeNode(10, None, TreeNode(20, None, TreeNode(30)))
        self.assertTrue(self.sol.isValidBST(root))

    def test_not_bst(self):
        # Test case: Not a BST
        root = TreeNode(10, TreeNode(15), TreeNode(5))
        self.assertFalse(self.sol.isValidBST(root))

    def test_large_bst(self):
        # Test case: Large BST with negative and positive values
        root = TreeNode(
            0,
            TreeNode(-10, TreeNode(-20), TreeNode(-5)),
            TreeNode(10, TreeNode(5), TreeNode(20))
        )
        self.assertTrue(self.sol.isValidBST(root))

if __name__ == '__main__':
    unittest.main()
