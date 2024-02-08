class Solution:
    def encode(self, strs):
        text = ''
        for string in strs:
            text += str(len(string)) + '#' + string
        return text

    def decode(self, s):
        result, i = [], 0

        while i < len(s):
            mark = s.index('#', i)
            length = int(s[i : mark])
            result.append(s[mark + 1 : mark + length + 1])
            i = mark + length + 1

        return result
