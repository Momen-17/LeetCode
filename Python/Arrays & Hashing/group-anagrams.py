class Solution(object):
    def groupAnagrams(self, strs):
        ret = {}
        for string in strs:
            sorted_string = ''.join(sorted(string))
            if sorted_string not in ret:
                ret[sorted_string] = []
            ret[sorted_string].append(string)
        
        return ret.values()