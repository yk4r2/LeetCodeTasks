class Solution:
    parenthesis = {
        ')': '(',
        ']': '[',
        '}': '{',
    }
    def isValid(self, s: str) -> bool:
        stack = []
        for symb in s:
            if symb in {'(', '[', '{'}:
                stack.append(symb)
            elif symb in self.parenthesis.keys():
                if not len(stack) or stack[-1] != self.parenthesis[symb]:
                    return False
                else:
                    stack.pop()
        return False if len(stack) else True

