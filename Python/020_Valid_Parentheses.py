class Solution(object):
    def isValid(self, s):
        if len(s) % 2 != 0 :
            return False
        mapp = {'(' : 1 , '{' : 2 , '[' : 3 , ']' : 4 , '}' : 5 , ')' : 6 }
        stack = []
        for item in s :
            if mapp[item] <= 3 :
                stack.append(item)
            else :
                temp = mapp[item]
                tmp = 0
                while True :
                    if len(stack) == 0 :
                        if tmp % 7 != 0 :
                            return False
                        break
                    k = stack.pop()
                    if mapp[k] + temp == 7 :
                        if tmp % 7 != 0 :
                            return False
                        break
                    tmp += mapp[k]
        if len(stack) != 0 :
            return False
        return True

