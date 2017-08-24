class Solution(object):
    def romanToInt(self, s):
        res = 0
        dicts = {'I':1, 'V':5,'X':10,'L':50,'C':100,'D':500 ,'M':1000 }
        for index , item in enumerate(s) :
            if index < len(s) - 1 and item in 'IXC' and dicts[item] < dicts[s[index+1]] :
                res -= dicts[item]
            else :
                res += dicts[item]
        return res



