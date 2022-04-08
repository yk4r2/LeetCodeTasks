class Solution:
    def minProductSum(self, nums1: List[int], nums2: List[int]) -> int:
        counter1, counter2 = [0] * 101, [0] * 101
        
        for num in nums1:
            counter1[num] += 1
        for num in nums2:
            counter2[num] += 1
        
        p1, p2 = 1, 100
        answer = 0
        
        while p1 <= 100 and p2 > 0:
            while p1 <= 100 and counter1[p1] == 0:
                p1 += 1
            while p2 > 0 and counter2[p2] == 0:
                p2 -= 1
            
            if p1 == 101 or p2 == 0:
                break
            
            min_count = min(counter1[p1], counter2[p2])
            answer += min_count * p1 * p2
            counter1[p1] -= min_count
            counter2[p2] -= min_count
        return answer
