/*
给定一个链表，判断链表中是否有环。
你能否不使用额外空间解决此题？

使用快慢指针
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
    bool hasCycle(ListNode *head) {
        if ( !head || !head->next ) 
            return false;
        ListNode* fast = head, *slow = head;
        while ( fast->next && fast->next->next ) {
            fast = fast->next->next;
            slow = slow->next;
            if ( fast == slow ) 
                return true;
        }
        return false;
    }
}; 