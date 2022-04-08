class Solution:
    def minProductSum(self, nums1: List[int], nums2: List[int]) -> int:
        nums1 = sorted(nums1)
        
        heap = [-num for num in nums2]
        heapq.heapify(heap)
        
        answer = 0
        for idx in range(len(nums2)):
            answer += nums1[idx] * (-heapq.heappop(heap))
        return answer
