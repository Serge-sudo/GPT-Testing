class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        def inorder_traversal(node):
            nonlocal first, second, prev
            if not node:
                return
            inorder_traversal(node.left)
            if prev and prev.val > node.val:
                if not first:
                    first = prev
                second = node
            prev = node
            inorder_traversal(node.right)
        
        first = second = prev = None
        inorder_traversal(root)
        first.val, second.val = second.val, first.val
