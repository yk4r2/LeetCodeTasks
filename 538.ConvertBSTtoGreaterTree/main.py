class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        prev_sum = 0
        pointer = root
        stack = []
        while stack or pointer:
            while pointer:
                stack.append(pointer)
                pointer = pointer.right

            pointer = stack.pop()
            prev_sum += pointer.val
            pointer.val = prev_sum
            
            pointer = pointer.left
        return root
