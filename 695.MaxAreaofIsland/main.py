class Solution:
    def calc_area(self, x: int, y: int) -> int:
        if self.grid[x][y] != 1:
            return 0
        self.grid[x][y] = -1
        app_x = [0, 1, 0, -1]
        app_y = [1, 0, -1, 0]
        appender = 0
        for dx, dy in zip(app_x, app_y):
            if 0 <= x + dx < len(self.grid) and 0 <= y + dy < len(self.grid[0]):
                appender += self.calc_area(x + dx, y + dy)
        return appender + 1
        
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        self.grid = grid
        max_area = 0
        for x_idx, row in enumerate(grid):
            for y_idx, elem in enumerate(row):
                if self.grid[x_idx][y_idx] == 1:
                    max_area = max(max_area, self.calc_area(x_idx, y_idx))
        return max_area
