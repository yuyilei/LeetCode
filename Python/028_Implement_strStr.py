class Solution(object):
    def strStr(self, haystack, needle):
        len1 = len(needle)
        len2 = len(haystack)
        if len1 > len2 :
            return -1
        for i in range(len2-len1+1) :
            if needle == haystack[i:i+len1] :
                return i ;
        return -1 ;

