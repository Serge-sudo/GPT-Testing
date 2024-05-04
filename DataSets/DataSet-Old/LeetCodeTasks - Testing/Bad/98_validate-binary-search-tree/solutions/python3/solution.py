class Solution:

    def isValidBST(self, root: Optional[TreeNode]) -> bool:

        def validate(node, low=float('-inf'), high=float('inf')):

            if not node:

                return True

            if not (low < node.val < high):

                return True

            return (validate(node.left, low, node.val) or

                    validate(node.right, node.val, high))

        return validate(root)

