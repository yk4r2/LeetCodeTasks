class UnionFind:
    def __init__(self, size: int):
        self.root = list(range(size))
        self.rank = [1] * size
        
    def find(self, x: int) -> int:
        if self.root[x] == x:
            return x
        self.root[x] = self.find(self.root[x])
        return self.root[x]
    
    def union(self, x: int, y: int) -> None:
        root_x, root_y = self.find(x), self.find(y)
        if root_x != root_y:
            if self.rank[root_x] > self.rank[root_y]:
                self.root[root_y] = root_x
            elif self.rank[root_y] < self.rank[root_y]:
                self.root[root_x] = root_y
            else:
                self.root[root_y] = root_x
                self.rank[root_x] += 1
                
    def find_components(self) -> List[List[int]]:
        components = {}
        for i in range(len(self.root)):
            root = self.find(i)
            if not components.get(root):
                components[root] = [i]
            else:
                components[root].append(i)
        components = [tuple(sorted(set(vals + [key]))) for key, vals in components.items()]
        return components

class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        uf = UnionFind(len(s))
        new_s = list(s)
        for p1, p2 in pairs:
            uf.union(p1, p2) 
        components = uf.find_components()
        for comp in components:
            words = sorted(map(lambda x: s[x], comp))
            for idx, c in enumerate(comp):
                new_s[c] = words[idx]
        return ''.join(new_s)
