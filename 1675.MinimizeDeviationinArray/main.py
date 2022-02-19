class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        evens = []
        min_num = inf
        
        for num in nums:
            if num % 2:
                evens.append(-num * 2)
                min_num = min(min_num, num * 2)
            else:
                evens.append(-num)
                min_num = min(min_num, num)

        heapq.heapify(evens)
        min_dev = inf
        while evens:
            current = -heapq.heappop(evens)
            min_dev = min(min_dev, current - min_num)
            if current % 2:
                break
            min_num = min(min_num, current // 2)
            heapq.heappush(evens, -current // 2)
        return min_dev
