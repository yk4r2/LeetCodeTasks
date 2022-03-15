class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        counter = 0
        new_string = []
        for word in s:
            if word == '(':
                counter += 1
            elif word == ')':
                if counter:
                    counter -= 1
                else:
                    continue
            new_string.append(word)

        back_counter = len(new_string) - 1
        while counter > 0:
            if new_string[back_counter] == '(':
                new_string.pop(back_counter)
                counter -= 1
            back_counter -= 1
        return "".join(new_string)
