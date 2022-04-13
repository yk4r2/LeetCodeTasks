class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        m, n = len(nums1), len(nums2)
        
        left_size = (m + n + 1) // 2
        start, end = 0, m
        is_even = not ((m + n) % 2)
        
        while start <= end:
            a_part = (start + end) // 2
            b_part = left_size - a_part
            
            a_left_max = float('-inf') if not a_part else nums1[a_part - 1]
            a_right_min = float('inf') if a_part == m else nums1[a_part]
            b_left_max = float('-inf') if not b_part else nums2[b_part - 1]
            b_right_min = float('inf') if b_part == n else nums2[b_part]
            
            if a_left_max <= b_right_min and b_left_max <= a_right_min:
                if not is_even:
                    return max(a_left_max, b_left_max)
                else:
                    return (max(a_left_max, b_left_max) + min(a_right_min, b_right_min)) / 2
            elif a_left_max > b_right_min:
                end = a_part - 1
            elif b_left_max > a_right_min:
                start = a_part + 1

