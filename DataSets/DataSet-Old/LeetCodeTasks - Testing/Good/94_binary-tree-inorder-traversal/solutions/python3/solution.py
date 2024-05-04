class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        stack = []
        result = []
        current = root
        
        while stack or current:
            while current:
                stack.append(current)
                current = current.left
                
            current = stack.pop()
            result.append(current.val)
            current = current.right
            
        return result
