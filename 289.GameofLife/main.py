cass Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        neighbors = ((0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1))
        
        rows, cols = len(board), len(board[0])
        for row in range(rows):
            for col in range(cols):
                alive = 0
                for dx, dy in neighbors:
                    new_r = row + dx
                    new_c = col + dy
                    
                    if new_r < rows and new_r >= 0 and new_c < cols and new_c >= 0 and abs(board[new_r][new_c]) == 1:
                        alive += 1
                if board[row][col] == 1 and (alive < 2 or alive > 3):
                    board[row][col] = -1
                if board[row][col] == 0 and alive == 3:
                    board[row][col] = 2

        for row in range(rows):
            for col in range(cols):
                if board[row][col] > 0:
                    board[row][col] = 1
                else:
                    board[row][col] = 0
