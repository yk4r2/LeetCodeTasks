from collections import defaultdict


class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        word_to_string = defaultdict(lambda: False)
        words = set()
        
        s = s.split(' ')
        
        if len(s) != len(pattern):
            return False
        for letter, word in zip(pattern, s):
            if not word_to_string[letter]:
                if word in words:
                    return False
                words.add(word)
                word_to_string[letter] = word
            elif word_to_string[letter] != word:
                return False
        return True


if __name__ == '__main__':
    print(Solution().wordPattern('abba', 'dog cat cat dog'))
