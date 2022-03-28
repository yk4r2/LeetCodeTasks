class UnionFind:
    def __init__(self, size: int):
        self.root = [i for i in range(size)]
        self.rank = [1] * size
        self.count = size

    def find(self, x: int) -> int:
        if x == self.root[x]:
            return x
        self.root[x] = self.find(self.root[x])
        return self.root[x]
    
    def union(self, x: int, y: int) -> int:
        root_x, root_y = self.find(x), self.find(y)
        if root_x != root_y:
            if self.rank[root_x] > self.rank[root_y]:
                self.root[root_y] = root_x
            elif self.rank[root_x] < self.rank[root_y]:
                self.root[root_x] = root_y
            else:
                self.root[root_y] = root_x
                self.rank[root_x] += 1
            self.count -= 1
            
    def connected(self, x: int, y: int) -> bool:
        return self.find(x) == self.find(y)
    
    def get_count(self) -> int:
        return self.count
        

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        if len(isConnected) < 1:
            return 0
        n = len(isConnected)
        uf = UnionFind(n)
        for row in range(n):
            for col in range(row + 1, n):
                if isConnected[row][col]:
                    uf.union(row, col)
        return uf.get_count()
