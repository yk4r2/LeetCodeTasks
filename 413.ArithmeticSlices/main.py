class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        if len(nums) < 3:
            return 0
        
        result = 0
        left = preright = 0
        right = 1
        diff = nums[right] - nums[preright]
        while right < len(nums):
            while right < len(nums) and nums[right] - nums[preright] == diff:
                preright += 1
                right += 1
            length = right - left
            if length >= 3:
                step = 2
                result += 1
                while (step + 1 < length):
                    result += step
                    step += 1
            left = preright = right - 1
            if right < len(nums):
                diff = nums[right] - nums[preright]
        return result
