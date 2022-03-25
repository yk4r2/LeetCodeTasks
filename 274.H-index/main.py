class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        buckets = [0] * (n + 2)
        for i in range(n):
            if citations[i] > n:
                buckets[n + 1] += 1
            else:
                buckets[citations[i]] += 1
            
        accumulator = buckets[n + 1]
        for h_idx in reversed(range(0, n+1)):
            accumulator += buckets[h_idx]
            if accumulator >= h_idx:
                return h_idx
        return 0

