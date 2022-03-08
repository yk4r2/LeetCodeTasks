class Solution:
    def newStroboNumber(self, n: int, final_len: int) -> str:
        if n == 0:
            return [""]
        elif n == 1:
            return ["0", "1", "8"]
        
        prev_nums = self.newStroboNumber(n - 2, final_len)
        curr_nums = []
        for prev in prev_nums:
            for pair in self.pairs:
                if pair[0] != '0' or n != final_len:
                    curr_nums.append(pair[0] + prev + pair[1])
        return curr_nums
        
    def findStrobogrammatic(self, n: int) -> List[str]:
        self.pairs = [
            ['0', '0'], ['1', '1'], ['8', '8'],
            ['6', '9'], ['9', '6'],
        ]
        return self.newStroboNumber(n, n)
