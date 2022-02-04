class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        return len(set(map(lambda s: re.sub('\.(?=.*@)|\+.*(?=@)', '', s), emails)))

