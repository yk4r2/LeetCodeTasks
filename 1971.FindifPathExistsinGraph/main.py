class Solution:
    def validPath(self, n: int, edges: List[List[int]], start: int, end: int) -> bool:
        adjacency_list = [[] for _ in range(n)]
        for a, b in edges:
            adjacency_list[a].append(b)
            adjacency_list[b].append(a)
        
        stack = [start]
        seen = set()
        
        while stack:
            node = stack.pop()
            
            if node == end:
                return True
            if node in seen:
                continue
                
            seen.add(node)
            for neighbor in adjacency_list[node]:
                stack.append(neighbor)
        return False
