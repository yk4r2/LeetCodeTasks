class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        setnums = set()
        for num in nums:
            if num in setnums:
                return True
            setnums.add(num)
        return False

