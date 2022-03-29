class UnionFind:
    def __init__(self, size):
        self.root = list(range(size))
        self.rank = [1] * size
    
    def find(self, x: int) -> int:
        if self.root[x] == x:
            return x
        self.root[x] = self.find(self.root[x])
        return self.root[x]
    
    def union(self, x: int, y: int) -> None:
        root_x = self.find(x)
        root_y = self.find(y)
        if self.rank[root_x] < self.rank[root_y]:
            self.root[root_y] = root_x
        elif self.rank[root_y] < self.rank[root_x]:
            self.root[root_x] = root_y
        else:
            self.root[root_y] = root_x
            self.rank[root_y] += 1
     
    def connected(self, x: int, y: int) -> bool:
        return self.find(x) == self.find(y)
    
    def count_components(self) -> int:
        return len(set(map(self.find, self.root)))


class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        uf = UnionFind(n)
        for x, y in edges:
            uf.union(x, y)
        return uf.count_components()
