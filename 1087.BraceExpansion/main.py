class Solution:
    def findAll(self, options: int, st: str) -> None:
        if options == len(self.possibilities):
            self.result.append(st)
            return
        for opt in self.possibilities[options]:
            self.findAll(options + 1, st + opt)
        
    def expand(self, s: str) -> List[str]:
        self.result = []
        idx = 0
        self.possibilities = []
        
        while idx < len(s):
            if s[idx] == '{':
                idx += 1
                x = ''
                while s[idx] != '}':
                    if s[idx].islower():
                        x += s[idx]
                    idx += 1
                self.possibilities.append(sorted(x))
            else:
                self.possibilities.append(s[idx])
            idx += 1
        self.findAll(0, '') 
        return self.result
