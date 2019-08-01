/*
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
*/


/*
 * 递归
 假设列表的其余部分已经被反转，现在我该如何反转它前面的部分？假设列表为：n1 → … → nk-1 → nk → nk+1 → … → nm → Ø

若从节点 nk+1 到 nm 已经被反转，而我们正处于 nk。

n1 → … → nk-1 → nk → nk+1 ← … ← nm

我们希望 nk+1 的下一个节点指向 nk。

所以，

nk.next.next = nk;

要小心的是 n1 的下一个必须指向 Ø 。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};


/*
 *迭代
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* cur = new ListNode(0);
        while (head) {
            ListNode* tmpnext = head->next;
            head->next = cur->next;
            cur->next = head;
            head = tmpnext;
        }
        return cur->next;
    }
};
