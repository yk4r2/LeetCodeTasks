class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        previous = {0: -1}
        max_len = 0
        part_sum = 0
        
        for idx, number in enumerate(nums):
            part_sum += 1 if number else -1
            if part_sum in previous:
                max_len = max(max_len, idx - previous[part_sum])
            else:
                previous[part_sum] = idx
        return max_len

