class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        subs = [1]
        for idx in range(1, len(nums)):
            less_idx = -1
            for jdx in range(0, idx):
                if nums[jdx] < nums[idx]:
                    if less_idx == -1:
                        less_idx = jdx
                    else:
                        less_idx = less_idx if subs[less_idx] > subs[jdx] else jdx
            if less_idx == -1:
                subs.append(1)
            else:
                subs.append(subs[less_idx] + 1)
        return max(subs)
