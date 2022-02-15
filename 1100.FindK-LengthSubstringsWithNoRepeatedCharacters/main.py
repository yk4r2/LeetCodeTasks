class Solution:
    def numKLenSubstrNoRepeats(self, s: str, k: int) -> int:
        if len(s) < k or k > 26:
            return 0
        left = right = 0
        freq = [0] * 26
        counter = 0
        while right < len(s):
            freq[ord(s[right]) - ord('a')] += 1
            while freq[ord(s[right]) - ord('a')] > 1:
                freq[ord(s[left]) - ord('a')] -= 1
                left += 1
            if right - left + 1 == k:
                counter += 1
                freq[ord(s[left]) - ord('a')] -= 1
                left += 1
            right += 1
        return counter
