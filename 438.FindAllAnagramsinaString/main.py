class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(s) < len(p):
            return []
        
        p_counter = [0] * 26
        s_counter = [0] * 26
        
        for char in p:
            p_counter[ord(char) - ord('a')] += 1
        
        result = []
        for sidx, snum in enumerate(s):
            s_counter[ord(snum) - ord('a')] += 1
            if sidx >= len(p):
                s_counter[ord(s[sidx - len(p)]) - ord('a')] -= 1
            if p_counter == s_counter:
                result.append(sidx - len(p) + 1)
        return result

