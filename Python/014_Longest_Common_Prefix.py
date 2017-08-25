class Solution(object):
    def longestCommonPrefix(self, strs):
        if len(strs) == 0 :
            return ""
        res = strs[0]
        for index , item in enumerate(strs) :
            if index != 0 :
                temp = []
                for i , j in zip(res,item) :
                    if i != j :
                        break
                    temp.append(i)
                tmp = "".join(temp)
                res = tmp
        return res
