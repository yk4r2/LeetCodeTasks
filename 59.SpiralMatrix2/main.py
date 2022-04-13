class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        directions = ((0, 1), (1, 0), (0, -1), (-1, 0))
        direction = 0
        row, col = 0, 0
        output = [[0 for i in range(n)] for _ in range(n)]
        for count in range(1, n * n + 1):
            output[row][col] = count
            count += 1
            r = (row + directions[direction][0]) % n
            c = (col + directions[direction][1]) % n
            if output[r][c]:
                direction += 1
                direction %= 4
            
            row += directions[direction][0]
            col += directions[direction][1]
        return output
