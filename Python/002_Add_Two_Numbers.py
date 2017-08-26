class Solution(object):
    def addTwoNumbers(self, l1, l2): 
        temp = 0 
        if l1 == None :
            return l2
        if l2 == None : 
            return l1
        res = l1 
        res.val += l2.val 
        if res.val >= 10 : 
            res.val -= 10 
            temp = 1 
        start = res 
        l1 = l1.next 
        l2 = l2.next 
        while l1 and l2 : 
            res.next = l1
            res = res.next 
            res.val += l2.val
            res.val += temp  
            temp = 0 
            if res.val >= 10 : 
                temp = 1 
                res.val -= 10 
            l1 = l1.next
            l2 = l2.next 
        while l1 : 
            res.next = l1 
            res = res.next 
            res.val += temp 
            temp = 0 
            if res.val >= 10 : 
                res.val -= 10 
                temp = 1 
            l1 = l1.next 
        while l2 : 
            res.next = l2 
            res = res.next 
            res.val += temp 
            temp = 0 
            if res.val >= 10 : 
                res.val -= 10 
                temp = 1 
            l2 = l2.next 
        if temp : 
            res.next = ListNode(temp) 
        return start 