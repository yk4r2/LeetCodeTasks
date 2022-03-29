class UnionFind:
    def __init__(self, size: int):
        self.root = list(range(size))
        self.rank = [1] * size
    
    def find(self, x: int) -> int:
        if x != self.root[x]:
            self.root[x] = self.find(self.root[x])
        return self.root[x]
    
    def union(self, x: int, y: int) -> None:
        root_x = self.find(x)
        root_y = self.find(y)
        
        if root_x != root_y:
            if self.rank[root_x] > self.rank[root_y]:
                self.root[root_y] = root_x
            elif self.rank[root_x] < self.rank[root_y]:
                self.root[root_x] = root_y
            else:
                self.root[root_y] = root_x
                self.rank[root_x] += 1
    
    def connected(self, x: int, y: int) -> bool:
        return self.find(x) == self.find(y)


class Solution:
    def maximumMinimumPath(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        dirs = ((1, 0), (0, 1), (-1, 0), (0, -1))
        uf = UnionFind(rows * cols)
        
        visited = [[False] * cols for _ in range(rows)]
        values = [(row, col) for row in range(rows) for col in range(cols)]
        values.sort(key=lambda x: grid[x[0]][x[1]], reverse=True)
        
        for row, col in values:
            pos = row * cols + col
            
            visited[row][col] = True
            for dx, dy in dirs:
                new_row = row + dx
                new_col = col + dy
                new_pos = new_row * cols + new_col
                in_bounds = 0 <= new_row < rows and 0 <= new_col < cols
                
                if in_bounds and visited[new_row][new_col]:
                    uf.union(pos, new_pos)
            if uf.connected(0, rows * cols - 1):
                return grid[row][col]
        return -1
