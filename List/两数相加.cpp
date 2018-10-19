/*
给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* tmp = res;
        int last = 0;
        while ( l1 || l2 ) {
            int num1 = ( l1 ) ? l1->val : 0;
            int num2 = ( l2 ) ? l2->val : 0;
            tmp->next = new ListNode((num1 + num2 + last)%10);
            tmp = tmp->next;
            last = ( num1 + num2 + last ) / 10;
            if ( l1 ) l1 = l1->next;
            if ( l2 ) l2 = l2->next;
        }
        if ( last != 0 )
            tmp->next = new ListNode(last);
        return res->next;
    }
};
