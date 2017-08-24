class Solution(object):
    def isPalindrome(self, x):
        str_x = str(x)
        max_index = len(str_x)
        for i in range(max_index/2) :
            temp = max_index - 1 - i
            if str_x[i] != str_x[temp] :
                return False
        return True

