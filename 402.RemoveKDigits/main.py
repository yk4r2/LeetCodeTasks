class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = [num[0]]
        
        for digit in num[1:]:
            while k and stack and stack[-1] > digit:
                stack.pop()
                k -= 1
            stack.append(digit)
            
        final_stack = stack[:-k] if k else stack
        return ''.join(final_stack).lstrip('0') or '0'
