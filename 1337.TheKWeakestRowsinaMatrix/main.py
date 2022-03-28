class Solution:
    def binary_search(self, row: List[int]) -> int:
        left, right = 0, len(row)
        while left < right:
            mid = left + (right - left) // 2
            if row[mid] == 1:
                left = mid + 1
            else:
                right = mid
        return left

    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        strengths = sorted(zip(map(self.binary_search, mat), range(len(mat))))
        return list(map(lambda x: x[1], strengths[:k]))
        
