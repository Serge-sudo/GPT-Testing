# test_solution.py

import unittest
from solution import Solution
from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __eq__(self, other):
        if not other or not isinstance(other, TreeNode):
            return False
        return self.val == other.val and self.left == other.left and self.right == other.right

    def __repr__(self):
        return f'TreeNode({self.val}, {self.left}, {self.right})'


def tree_to_list(root: Optional[TreeNode]) -> List[Optional[int]]:
    """Convert a binary tree to a list representation using level-order traversal."""
    if not root:
        return []

    result, queue = [], [root]
    while queue:
        node = queue.pop(0)
        if node:
            result.append(node.val)
            queue.append(node.left)
            queue.append(node.right)
        else:
            result.append(None)

    while result and result[-1] is None:
        result.pop()
    return result


class TestSolution(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def assertBSTsEqual(self, actual_trees, expected_values):
        """Helper to compare list of BST trees to expected list of lists."""
        actual_lists = sorted([tree_to_list(tree) for tree in actual_trees])
        expected_lists = sorted(expected_values)
        self.assertEqual(actual_lists, expected_lists)

    def test_generate_trees(self):
        test_cases = [
            (1, [[1]]),
            (2, [[1, None, 2], [2, 1]]),
            (3, [
                [1, None, 2, None, 3],
                [1, None, 3, 2],
                [2, 1, 3],
                [3, 1, None, None, 2],
                [3, 2, None, 1]
            ]),
        ]

        for n, expected in test_cases:
            with self.subTest(n=n):
                result = self.solution.generateTrees(n)
                self.assertBSTsEqual(result, expected)


if __name__ == '__main__':
    unittest.main()
