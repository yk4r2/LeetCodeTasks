class Solution:
    def reverseSwap(self, s: List[str], idx: int, jdx: int) -> None:
        buf = s[idx]
        s[idx] = s[jdx]
        s[jdx] = buf
        
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        idx, jdx = 0, len(s) - 1
        while idx < jdx:
            self.reverseSwap(s, idx, jdx)
            idx += 1
            jdx -= 1

