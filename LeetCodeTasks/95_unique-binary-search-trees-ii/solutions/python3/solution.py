from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        if n == 0:
            return []
        return self.generate_trees_helper(1, n)
    
    def generate_trees_helper(self, start, end):
        if start > end:
            return [None]
        result = []
        for i in range(start, end + 1):
            left_trees = self.generate_trees_helper(start, i - 1)
            right_trees = self.generate_trees_helper(i + 1, end)
            for left in left_trees:
                for right in right_trees:
                    root = TreeNode(i)
                    root.left = left
                    root.right = right
                    result.append(root)
        return result
