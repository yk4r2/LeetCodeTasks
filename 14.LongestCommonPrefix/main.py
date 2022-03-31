class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = []
        for i in range(min(map(len, strs))):
            first = strs[0][i]
            if all(map(lambda x: first == x[i], strs)):
                prefix.append(first)
            else:
                break
        return ''.join(prefix)
