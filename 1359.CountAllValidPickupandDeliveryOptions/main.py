class Solution:
    def countOrders(self, n: int) -> int:
        return reduce(lambda a, i: a * i * (2 * i - 1) % int(1e9 + 7), range(1, n + 1), 1)
