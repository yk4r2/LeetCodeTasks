class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        modulo = int(1e9 + 7)
        count = [0] * 101
        for num in arr:
            count[num] += 1
        answer = 0

        # x != y != z
        for x in range(101):
            for y in range(x + 1, 101):
                z = target - (x + y)
                if y < z <= 100:
                    answer += count[x] * count[y] * count[z]
                    answer %= modulo
        
        # x == y
        for x in range(101):
            z = target - 2 * x
            if x < z <= 100:
                answer += count[x] * (count[x] - 1) / 2 * (count[z])
                answer %= modulo
        
        # y == z
        for x in range(101):
            if not (target - x) % 2:
                y = int((target - x) / 2)
                if x < y <= 100:
                    answer += count[x] * count[y] * (count[y] - 1) / 2
                    answer %= modulo
        
        # x == y == z
        if not target % 3:
            x = int(target / 3)
            if 0 <= x <= 100:
                answer += count[x] * (count[x] - 1) * (count[x] - 2) / 6
                answer %= modulo
        return int(answer)
