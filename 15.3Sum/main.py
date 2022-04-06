class Solution:
    def twoSum(self, nums: List[int], idx: int, res: List[List[int]]):
        seen = set()
        fast = idx + 1
        while fast < len(nums):
            complement = -nums[idx] - nums[fast]
            if complement in seen:
                res.append([nums[idx], nums[fast], complement])
                while fast + 1 < len(nums) and nums[fast] == nums[fast + 1]:
                    fast += 1
            seen.add(nums[fast])
            fast += 1
        
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        for left in range(len(nums)):
            if nums[left] > 0:
                break
            if left == 0 or nums[left - 1] != nums[left]:
                self.twoSum(nums, left, res)
        return res
