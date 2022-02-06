class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return len(nums)
        fast = 1
        slow = 0
        newpointer = 0
        while fast < len(nums):
            while fast < len(nums) and nums[fast] == nums[slow]:
                fast += 1
            if fast - slow == 1:
                nums[newpointer] = nums[slow]
                newpointer += 1
            else:
                nums[newpointer] = nums[slow]
                newpointer += 1
                slow += 1
                nums[newpointer] = nums[slow]
                newpointer += 1
            slow = fast
        return newpointer
