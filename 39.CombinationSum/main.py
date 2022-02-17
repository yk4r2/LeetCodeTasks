class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        path = [None] * (target+1)
        path[0] = [[]]
        for cand in candidates:
            for num in range(cand, target + 1):
                if not path[num]:
                    path[num] = []
                temp = []
                previous = path[num - cand] if path[num - cand] else []
                for prev in previous:
                    temp.append(prev + [cand])
                if temp:
                    path[num].extend(temp)
        return path[target]
