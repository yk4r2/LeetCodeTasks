class Solution:
   def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        new_grid = [[0] * len(grid[0]) for _ in range(len(grid))]
        rows, cols = len(grid), len(grid[0])
        for row in range(rows):
            for col in range(cols):
                new_col = (col + k) % cols
                appender = (col + k) // cols
                new_row = (row + appender) % rows
                new_grid[new_row][new_col] = grid[row][col]
        return new_grid
