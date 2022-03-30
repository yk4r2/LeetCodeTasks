class UnionFind:
    def __init__(self, size: int):
        self.root = list(range(size))
        self.rank = [1] * size
        self.components = size
    
    def find(self, x: int) -> int:
        if x == self.root[x]:
            return x
        self.root[x] = self.find(self.root[x])
        return self.root[x]
    
    def union(self, x: int, y: int) -> None:
        root_x = self.find(x)
        root_y = self.find(y)
        if root_x != root_y:
            if self.rank[root_x] < self.rank[root_y]:
                self.root[root_x] = root_y
            elif self.rank[root_x] > self.rank[root_y]:
                self.root[root_y] = root_x
            else:
                self.root[root_y] = root_x
                self.rank[root_x] += 1
            self.components -= 1
    
    def connected(self, x: int, y: int) -> bool:
        return self.find(x) == self.find(y)
    
class Solution:
    def earliestAcq(self, logs: List[List[int]], n: int) -> int:
        logs = sorted(logs)
        uf = UnionFind(n)
        for timestamp, f1, f2 in logs:
            uf.union(f1, f2)
            if uf.components == 1:
                return timestamp
        return -1
