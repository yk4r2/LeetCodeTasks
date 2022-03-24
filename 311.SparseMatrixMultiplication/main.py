class Solution:
    @staticmethod
    def compressMatrix(matrix: List[List[int]]) -> List[List[Tuple[int]]]:
        result = [[] for _ in range(len(matrix))]
        for row in range(len(matrix)):
            for col in range(len(matrix[0])):
                if matrix[row][col]:
                    result[row].append([matrix[row][col], col])
        return result
        
    def multiply(self, mat1: List[List[int]], mat2: List[List[int]]) -> List[List[int]]:
        m = len(mat1)
        k = len(mat1[0])
        n = len(mat2[0])
        
        mat1 = self.compressMatrix(mat1)
        mat2 = self.compressMatrix(mat2)
        
        answer = [[0] * n for _ in range(m)]
        
        for row in range(m):
            for elem1, place1 in mat1[row]:
                for elem2, place2 in mat2[place1]:
                    answer[row][place2] += elem1 * elem2
        return answer
