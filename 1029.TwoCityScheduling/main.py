class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        costs = sorted(costs, key=lambda x: x[0] - x[1])
        total, size = 0, len(costs) // 2
        return reduce(lambda a, x: a + x[0][0] + x[1][1], zip(costs[:size], costs[size:]), 0)
