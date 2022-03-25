class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        costs = sorted(costs, key=lambda x: x[0] - x[1])
        total = 0
        size = len(costs) // 2
        for i in range(size):
            total += costs[i][0] + costs[i + size][1]
        return total
