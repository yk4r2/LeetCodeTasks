class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        raw = s.upper().split('-')
        raw = ''.join(raw)
        output = ""
        
        if k == 1:
            return "-".join(list(raw))
        
        while len(raw) > k:
            output = "-" + raw[-k:] + output
            raw = raw[:-k]
        
        if len(raw) > 0:
            return raw + output
        else:
            return output[1:]
