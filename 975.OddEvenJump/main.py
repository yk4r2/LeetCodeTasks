class Solution:
    def next_index(self, indices: List[int]) -> List[int]:
        stack = []
        result = [None] * len(indices)
 
        for idx in indices:
            while stack and idx > stack[-1]:
                result[stack.pop()] = idx
            stack.append(idx)
        return result
 
    def oddEvenJumps(self, arr: List[int]) -> int:
        sorted_idx = sorted(range(len(arr)), key = lambda x: arr[x])
        odd_indices = self.next_index(sorted_idx)
        sorted_idx = sorted(range(len(arr)), key = lambda x: -arr[x])
        even_indices = self.next_index(sorted_idx)
 
        dp = [[0, 1] for _ in range(len(arr))]
        for i in range(len(arr)):
            if odd_indices[i]:
                dp[odd_indices[i]][0] += dp[i][1]
            if even_indices[i]:
                dp[even_indices[i]][1] += dp[i][0]
        return dp[-1][0] + dp[-1][1]
