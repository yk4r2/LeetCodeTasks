class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return max(map(self.maxDepth, [root.left, root.right])) + 1 if root else 0
