class Solution:
    def calPoints(self, ops: List[str]) -> int:
        record = []
        for i in ops:
            if i == '+':
                record.append(record[-2] + record[-1])
            elif i == 'D':
                record.append(record[-1] * 2)
            elif i == 'C':
                record = record[:-1]
            else:
                record.append(int(i))
        return sum(record)
