/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

说明：不允许修改给定的链表。

进阶：
你是否可以不用额外空间解决此题？
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
    ListNode *detectCycle(ListNode *head) {
        if ( !head || !head->next )
            return NULL;
        ListNode *low = head, *fast = head;
        while ( low && fast ) {
            if ( !low->next || !fast->next || !fast->next->next )
                return NULL;
            low = low->next;
            fast = fast->next->next;
            if ( low == fast )
                break;
        }
        ListNode *res = head;
        while ( low != res ) {
            low = low->next;
            res = res->next;
        }
        return res;
    }
};
