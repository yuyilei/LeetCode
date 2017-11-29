/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 迭代法： 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *res = NULL ; 
        for ( ; head ; head = head->next ){
            ListNode* tmp =  new ListNode(head->val) ;  
            tmp->next = res ; 
            res = tmp ; 
        }
        return res ; 
    }
};

// 递归法：
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if ( !head || !head->next ) 
            return head ; 
        ListNode* next = head->next ; 
        ListNode* newhead = reverseList(next) ; 
        next->next = head ; 
        head->next = NULL ; 
        return newhead ; 
    }   
};