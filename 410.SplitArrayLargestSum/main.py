class Solution:
    def minSubarrays(self, nums: List[int], boundary: int) -> int:
        current_sum = 0
        splits = 0
        for element in nums:
            if current_sum + element <= boundary:
                current_sum += element
            else:
                current_sum = element
                splits += 1
        return splits + 1
        
    def splitArray(self, nums: List[int], m: int) -> int:
        left = max(nums)
        right = sum(nums)
        min_largest_sum = sum(nums)    
        while left <= right:
            mid = (right + left) // 2
            if self.minSubarrays(nums, mid) <= m:
                right = mid - 1
                min_largest_sum = mid
            else:
                left = mid + 1
        return min_largest_sum
