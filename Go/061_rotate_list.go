/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func rotateRight(head *ListNode, k int) *ListNode {
    if head == nil {
        return head 
    }
    num := 1 
    last := head
    for ; last.Next != nil ; last = last.Next {
        num++ 
    }
    k %= num
    if k == 0 {
        return head  
    }
    first := head
    for i := 1 ; i < num - k ; first = first.Next {
        i++ 
    }
    res := first.Next
    first.Next = nil 
    last.Next = head
    return res
} 