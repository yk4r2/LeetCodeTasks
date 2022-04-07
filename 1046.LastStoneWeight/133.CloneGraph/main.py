class Solution:
    def __init__(self):
        self.visited = {}

    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return node
        
        if node in self.visited:
            return self.visited[node]
        
        copy = Node(node.val, [])
        self.visited[node] = copy
        
        if node.neighbors:
            copy.neighbors = [self.cloneGraph(n) for n in node.neighbors]
        return copy
