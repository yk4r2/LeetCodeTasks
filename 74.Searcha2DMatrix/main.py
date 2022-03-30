class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False
        rows, cols = len(matrix), len(matrix[0])
        if not matrix[0][0] <= target <= matrix[rows - 1][cols - 1]:
            return False
        row, col = 0, cols - 1
        while row < rows and col >= 0:
            if matrix[row][col] == target:
                return True
            if matrix[row][col] < target:
                row += 1
            else:
                col -= 1
        return False