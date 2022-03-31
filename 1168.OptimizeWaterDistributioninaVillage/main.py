class UnionFind:
    def __init__(self, size: int):
        self.root = list(range(size + 1))
        self.rank = [1] * (size + 1)
    
    def find(self, x: int) -> int:
        if self.root[x] == x:
            return x
        self.root[x] = self.find(self.root[x])
        return self.root[x]
    
    def union(self, x: int, y: int):
        root_x = self.find(x)
        root_y = self.find(y)
        if root_x != root_y:
            if self.rank[root_x] > self.rank[root_y]:
                self.root[root_y] = root_x
            elif self.rank[root_y] > self.rank[root_x]:
                self.root[root_x] = root_y
            else:
                self.root[root_y] = root_x
                self.rank[root_x] += 1

    def connected(self, x: int, y: int):
        return self.find(x) == self.find(y)


class Solution:
    def minCostToSupplyWater(self, n: int, wells: List[int], pipes: List[List[int]]) -> int:
        edges = []
        for idx, weight in enumerate(wells):
            edges.append((weight, 0, idx + 1))

        for house_a, house_b, weight in pipes:
            edges.append((weight, house_a, house_b))
        
        edges = sorted(edges)
        
        uf = UnionFind(n)
        total = 0
        
        for cost, house_a, house_b in edges:
            if not uf.connected(house_a, house_b):
                uf.union(house_a, house_b)
                total += cost
        return total
