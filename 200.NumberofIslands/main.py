class Solution:
    def bfs(self, r: int, c: int, grid: List[List[str]], visited: List[List[bool]]) -> List[List[str]]:
        if grid[r][c] != '1' or visited[r][c]:
            return visited
        
        visited[r][c] = True
        drs = [0, 1, 0, -1]
        dcs = [1, 0, -1, 0]
        for dr, dc in zip(drs, dcs):
            if (0 <= r + dr < len(grid) and 0 <= c + dc < len(grid[0])):
                visited = self.bfs(r + dr, c + dc, grid, visited)
        return visited
        
    def numIslands(self, grid: List[List[str]]) -> int:
        result = 0
        visited = [[False for i in range(len(grid[0]))] for j in range(len(grid))]
        for idx_r, row in enumerate(grid):
            for idx_c, c in enumerate(row):
                if c == '1' and not visited[idx_r][idx_c]:
                    result += 1
                    visited = self.bfs(idx_r, idx_c, grid, visited)
        return result

