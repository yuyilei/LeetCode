/*
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
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
        ListNode* res = new ListNode(0);
        // ListNode* cur = res;
        while (head) {
            ListNode* tmp = head->next;
            head->next = res->next;
            res->next = head;
            head = tmp;
        }
        return res->next;
    }
};
