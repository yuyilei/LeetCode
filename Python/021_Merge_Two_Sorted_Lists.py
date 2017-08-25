# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        if l1 == None :
            return l2
        if l2 == None :
            return l1
        if l1.val > l2.val :
            res = l2
            l2 = l2.next
        else :
            res = l1
            l1 = l1.next
        start = res
        while l1 and l2 :
            if l1.val > l2.val :
                res.next = l2
                res = l2
                l2 = l2.next
            else :
                res.next = l1
                res = l1
                l1 = l1.next
        while l1 :
            res.next = l1
            res = l1
            l1 = l1.next
        while l2 :
            res.next = l2
            res = l2
            l2 = l2.next
        return start
