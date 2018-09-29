/*
请判断一个链表是否为回文链表。
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
*/
/*
先用快慢指针找出链表的中间节点，然后反转后半部分链表，判断前后半段链表是否相等. 
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
    bool isPalindrome(ListNode* head) {
        if ( !head ) 
            return true;
        ListNode* fast = head, *slow = head;
        while ( fast->next && fast->next->next ) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = ReverseList(slow->next);
        slow = slow->next; 
        while ( slow ) {
            if ( head->val != slow->val ) 
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
    ListNode* ReverseList(ListNode* head){
        ListNode* res = NULL;
        while ( head ) {
            ListNode* next = head->next;
            head->next = res;
            res = head;
            head = next;
        }
        return res;
    }
};  