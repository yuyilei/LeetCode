/*
反转一个单链表。
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
        ListNode* res = NULL;
        for ( ListNode* now = head; now ; ) {
            ListNode* temp = now->next;
            now->next = res;
            res = now;
            now = temp;
        }
        return res;
    }
};