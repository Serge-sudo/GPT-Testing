import unittest
from solution import Solution, TreeNode

class TestInorderTraversal(unittest.TestCase):
    def tree_from_list(self, vals):
        """Helper function to construct a binary tree from a list of values (level order)."""
        if not vals:
            return None
        nodes = [TreeNode(val) if val is not None else None for val in vals]
        kids = nodes[::-1]
        root = kids.pop()
        for node in nodes:
            if node:
                if kids:
                    node.left = kids.pop()
                if kids:
                    node.right = kids.pop()
        return root

    def test_inorder_traversal(self):
        sol = Solution()

        # Test case 1
        root1 = self.tree_from_list([1, None, 2, 3])
        self.assertEqual(sol.inorderTraversal(root1), [1, 3, 2])

        # Test case 2
        root2 = self.tree_from_list([])
        self.assertEqual(sol.inorderTraversal(root2), [])

        # Test case 3
        root3 = self.tree_from_list([1])
        self.assertEqual(sol.inorderTraversal(root3), [1])

        # Additional cases
        root4 = self.tree_from_list([3, 1, 4, None, 2])
        self.assertEqual(sol.inorderTraversal(root4), [1, 2, 3, 4])

        root5 = self.tree_from_list([5, 3, 6, 2, 4, None, None, 1])
        self.assertEqual(sol.inorderTraversal(root5), [1, 2, 3, 4, 5, 6])

if __name__ == '__main__':
    unittest.main()
