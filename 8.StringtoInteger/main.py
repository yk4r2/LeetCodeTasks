mapper = {
    '1': 1,
    '2': 2,
    '3': 3,
    '4': 4,
    '5': 5,
    '6': 6,
    '7': 7,
    '8': 8,
    '9': 9,
    '0': 0,
}

INT_MAX = 2**31 - 1
INT_MIN = -2**31


class Solution:
    def stripper(self, x: int) -> int:
        if x > INT_MAX:
            return INT_MAX
        return INT_MIN if x < INT_MIN else x

    def myAtoi(self, s: str) -> int:
        s = s.lstrip(' ')
        if not s:
            return 0
          
        sign = -1 if s[0] == '-' else 1
        if sign != 1 or s[0] == '+':
            s = s[1:]
        
        result = 0
        for ch in s:
            if ch not in mapper.keys():
                return self.stripper(result * sign)
            result *= 10
            result += mapper[ch]
        return self.stripper(result * sign)

