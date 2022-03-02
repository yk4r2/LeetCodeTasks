class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if not s:
            return True
        if not t:
            return False
        s_pointer = 0
        t_pointer = 0
        while (s_pointer < len(s) and t_pointer < len(t)):
            if s[s_pointer] == t[t_pointer]:
                s_pointer += 1
            t_pointer += 1
        return s_pointer >= len(s)
