class Solution(object):
    def deleteDuplicates(self, head):
        if head == None :
            return None
        res = head
        start = res
        head = head.next
        while head :
            if head.val != res.val :
                res.next = head
                res = res.next
            head = head.next
        res.next = None  # 把res 后续的节点去掉
        return start  # 返回初始节点
