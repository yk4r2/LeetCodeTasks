class Solution:
    def DFS(self, node: int) -> bool:
        if len(self.adjacency_matrix[node]) == 0:
            return node == self.destination
        for neighbor in self.adjacency_matrix[node]:
            if neighbor in self.visited:
                return False
            self.visited.add(neighbor)
            
            if not self.DFS(neighbor):
                return False
            self.visited.remove(neighbor)
        return True
            
        
    def leadsToDestination(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        self.adjacency_matrix = defaultdict(list)
        self.destination = destination
        for a, b in edges:
            self.adjacency_matrix[a].append(b)
        
        if len(self.adjacency_matrix[destination]):
            return False
        
        self.visited = set()
        return self.DFS(source)
