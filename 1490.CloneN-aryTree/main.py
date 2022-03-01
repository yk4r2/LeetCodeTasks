class Solution:
    def cloneTree(self, root: 'Node') -> 'Node':
        if not root:
            return root
        
        copied_root = Node(root.val)
        queue = deque([(root, copied_root)])
        while queue:
            old_node, copied_node = queue.popleft()
            for child in old_node.children:
                copied_child = Node(child.val)
                copied_node.children.append(copied_child)
                queue.append((child, copied_child))
        return copied_root
