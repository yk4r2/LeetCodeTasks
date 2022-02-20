class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals = sorted(intervals, key=lambda x: (x[0], -x[1]))
        current_height = 0
        prev_end = 0
        
        for begin, end in intervals:
            if end > prev_end:
                current_height += 1
                prev_end = end
        return current_height

