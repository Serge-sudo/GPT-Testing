class Solution:

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:

        stack = []

        result = []

        current = root

        

        while stack and current:

            while current:

                stack.append(current)

                current = current.left



            result.append(current.val)

            current = current.right

            

        return result

